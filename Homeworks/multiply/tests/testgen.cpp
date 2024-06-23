#include "testlib.h"
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename Type>
using OSet = tree <Type, null_type, std::less <Type>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long llong;
const std::string TASK_NAME = "gcd3";
const int MAXN = 200000 + 10;
const int MAXNUM = 1e7 + 10;
const int INF = 1e9;

int ID;
int minN[] = {0, 499950, 95, 95, 2450, 99500, 499500};
int maxN[] = {20, 500000, 100, 100, 2500, 100000, 500000};
int maxA[] = {100, 10000000, 10000, 10000000, 10000000, 500000, 10000000};
bool onlyPrimes[] = {0, 1, 0, 0, 0, 0, 0};
int from[] = {1, 3, 13, 23, 33, 43, 53};

int randomN()
{
    return rnd.next(maxN[ID] - minN[ID] + 1) + minN[ID];
}

int percent(int num, int p)
{
    return (p * num) / 100;
}

int percentRnd(int num, int p)
{
    int p2 = p + rnd.next(5) - 2;
    p2 = std::max(0, p2);
    p2 = std::min(100, p2);
    return percent(num, p2);
}

int myLog(int num)
{
    int lg = 0;
    while ((1 << lg + 1) <= num)
    {
        lg++;
    }

    return lg;
}

int lowDiv[MAXNUM];
std::vector <int> primes;
std::vector <int> smallPrimes;
void sieve(int max)
{
    std::fill(lowDiv + 2, lowDiv +  max + 1, INF);
    for (int num = 2 ; num <= max ; ++num)
    {
        if (lowDiv[num] != INF)
        {
            continue;
        }

        if (1LL * num * num * num <= max)
        {
            smallPrimes.push_back(num);
        }

        // std::cout << "prime: " << num << '\n' << std::flush;
        primes.push_back(num);
        lowDiv[num] = num;

        for (int j = 2 * num ; j <= max ; j += num)
        {
            lowDiv[j] = std::min(lowDiv[j], num);
        }
    }

    // std::cout << "here: " << primes.size() << ' ' << maxA[ID] << ' ' << maxN[ID] << '\n';
}

int myPrimeLog(int num)
{
    int lg = 0;
    llong prod = 1;
    while (prod * primes[lg] <= num)
    {
        prod *= primes[lg];
        lg++;
    }

    return lg;
}

int myRealLog(int num, int by)
{
    int lg = 0;
    while (num >= by)
    {
        num /= by;
        lg++;
    }

    return lg;
}

std::vector <int> myPartition(int times, int sum, int minpart, int maxpart)
{
    assert(sum <= times * maxpart);
    assert(sum >= times * minpart);
    sum -= times * minpart;
    maxpart -= minpart;
        
    std::vector <int> sol;
    while (times > 0)
    {
        if (sum == 0)
        {
            sol.push_back(0);
            times--;
            continue;
        }

        assert(times > 0);
        int curr = std::max(sum - (times - 1) * maxpart, std::min(rnd.next(maxpart) + 1, sum));
        sol.push_back(curr);
        sum -= curr;
        times--;
    }

    assert(times == 0);
    for (int &val : sol)
    {
        val += minpart;
    }

    return sol;
}

struct Test
{
    std::vector <int> s;
    std::vector <std::vector <int>> split;
    std::vector <std::vector <int>> primeSplit;
    int n, answer;

    void initialize(int _n, int _answer)
    {
        n = _n;
        answer = _answer;
        s.clear();
        split.clear();
        primeSplit.clear();
        s.resize(n, 1);
    }

    void makeSplit()
    {
        std::vector <int> order, groupSize;
        order.resize(n);
        
        std::iota(order.begin(), order.end(), 0);
        shuffle(order.begin(), order.end());
        groupSize = rnd.partition(answer, n, 1);
        int ptr = 0;

        split.resize(answer);
        for (int i = 0 ; i < answer ; ++i)
        {
            split[i].reserve(groupSize[i]);
            for (int j = 0 ; j < groupSize[i] ; ++j)
            {
                split[i].push_back(order[ptr++]);
            }
        }
    }

    void makePrimeSplit(bool reversed)
    {
        primeSplit.resize(answer);
        std::vector <int> candidates = primes;
        if (onlyPrimes[ID])
        {
            shuffle(candidates.begin(), candidates.end());
            while (candidates.size() > answer)
            {
                candidates.pop_back();
            }

            assert(candidates.size() == answer);
            for (int i = 0 ; i < answer ; ++i)
            {
                assert(candidates[i] != 1);
                primeSplit[i].push_back(candidates[i]);
            }
            
            return;
        }

        int cnt = rnd.next(2) + 2;
        while (candidates.size() > cnt * answer)
        {
            candidates.pop_back();
        }

        if (reversed)
        {
            for (const int &p : primes)
            {
                if (p * p > maxA[ID])
                {
                    break;
                }

                candidates.push_back(p);
            }

            std::reverse(candidates.begin(), candidates.end());
            while (candidates.size() > 2 * answer) candidates.pop_back();
            // std::cout << "primes\n";
            // for (const int &p : candidates)
            // {
            //     std::cout << p << ' ';
            // }

            // std::cout << '\n';
        }

        std::vector <int> groupSize;

        // std::cout << "here\n" << std::flush;
        bool shouldBreak = true;
        do 
        {
            shouldBreak = true;
            groupSize = myPartition(answer, (int)candidates.size(), 1, (reversed ? 2 : 4));
            for (const int &sz : groupSize)
            {
                // std::cout << "sz: " << sz << '\n';
                if (sz > 7)
                {
                    shouldBreak = false;
                    // break;
                }
            }

            // std::cout << "here1: " << candidates.size() << ' ' << answer << "\n" << std::flush;
        } while (!shouldBreak);        

        shuffle(primeSplit.begin(), primeSplit.end());
        int ptr = 0;
        primeSplit.resize(answer);
        for (int i = 0 ; i < answer ; ++i)
        {
            primeSplit[i].reserve(groupSize[i]);
            for (int j = 0 ; j < groupSize[i] ; ++j)
            {
                primeSplit[i].push_back(candidates[ptr++]);
            }
        }
    }

    void addEdge(int comp, int u, int v)
    {
        if (std::__gcd(s[u], s[v]) != 1)
        {
            return;
        }

        // std::cout << "before adding: " << comp << ' ' << primeSplit[comp].size() << ' ' << s[1369] << ' ' << s[2739] << "\n";
        // for (const int &p : primeSplit[comp]) std::cout << p << '\n' << std::flush;

        std::vector <int> primes = primeSplit[comp];
        shuffle(primes.begin(), primes.end());
        for (int &p : primes)
        {
            // std::cout << "try adding edge: " << u << ' ' << v << ' ' << s[u] << ' ' << s[v] << ' ' << p << ' ' << maxA[ID] << '\n';
            if (s[u] % p == 0 && 1LL * s[v] * p <= maxA[ID])
            {
                s[v] *= p;
                return;
            }

            if (s[v] % p == 0 && 1LL * s[u] * p <= maxA[ID])
            {
                s[u] *= p;
                return;
            }

            if (1LL * std::max(s[u], s[v]) * p > maxA[ID])
            {
                continue;
            }

            s[u] *= p;
            s[v] *= p;
            return;
        }

        std::cout << "FAIL!\n";
        exit(0);
    }

    void buildComponent(int compIdx, int t, int p)
    {
        for (const int &pos : split[compIdx])
        {
            assert(s[pos] == 1);
        }

        // std::cout << "begin building: " << compIdx << ' ' << s[1369] << ' ' << s[2739] << "\n";
        // for (const int &num : primeSplit[compIdx])
        // {
        //     std::cout << num << ' ';
        // }

        // std::cout << '\n';

        if (split[compIdx].size() == 1)
        {
            assert(primeSplit[compIdx][0] <= maxA[ID]);
            s[split[compIdx][0]] = primeSplit[compIdx][0];
        }

        for (int i = 1 ; i < split[compIdx].size() ; ++i)
        {
            int u = split[compIdx][rnd.wnext(i, t)];
            int v = split[compIdx][i];
            addEdge(compIdx, u, v);
            // std::cout << "add edge: " << u << ' ' << v << '\n';
        }

        // std::cout << "done building: " << compIdx << "\n";
        // for (const int &num : primeSplit[compIdx])
        // {
        //     std::cout << num << ' ';
        // }

        // std::cout << '\n';
        if (onlyPrimes[ID]) return;
        llong tries = percentRnd(1LL * split[compIdx].size() * myPrimeLog(maxA[ID]), rnd.next(p / 2 + 1) + p - p / 2);
        // std::cout << "tries: " << tries << '\n'; 
        for (int i = 0 ; i < tries ; ++i)
        {
            int pos = split[compIdx][rnd.next(split[compIdx].size())];
            int prime = primeSplit[compIdx][rnd.next(primeSplit[compIdx].size())];
            if (1LL * s[pos] * prime <= maxA[ID])
            {
                s[pos] *= prime;
            }
        }
    }

    int buildComponent2(int compIdx, int reachedPrime, int t, int p)
    {
        for (const int &pos : split[compIdx])
        {
            assert(s[pos] == 1);
        }

        int startPtr = reachedPrime;
        while (1LL * s[split[compIdx][0]] * primes[reachedPrime] <= maxA[ID])
        {
            s[split[compIdx][0]] *= primes[reachedPrime];
            reachedPrime++;
        }   

        for (int tries = 0 ; tries < 2 ; ++tries)
        {
            int curr = rnd.next(startPtr, reachedPrime - 1);
            if (1LL * s[split[compIdx][0]] * primes[curr] <= maxA[ID])
            {
                s[split[compIdx][0]] *= primes[curr];
            }
        }

        for (int i = 1 ; i < split[compIdx].size() ; ++i)
        {
            int p;
            if (startPtr + i - 1 < reachedPrime) p = primes[startPtr + i - 1];
            else p = primes[rnd.next(startPtr, reachedPrime - 1)];

            int times = rnd.next(1, myRealLog(maxA[ID], p));
            for (int j = 0 ; j < times ; ++j)
            {
                s[split[compIdx][i]] *= p;
            }
        }

        return reachedPrime;
    }

    void testPrint()
    {
        std::cout << n << '\n';
        for (int i = 0 ; i < n ; ++i)
        {
            std::cout << s[i] << ' ';
        }

        std::cout << answer << '\n';
        std::cout << "comps: " << answer << "\n";
        for (int i = 0 ; i < answer ; ++i)
        {
            for (const int &pos : split[i])
            {
                std::cout << pos << ' ';
            }

            std::cout << '\n';
        }

        std::cout << "prime distribution\n";
        for (int i = 0 ; i < answer ; ++i)
        {
            for (const int &p : primeSplit[i])
            {
                std::cout << p << ' ';
            }

            std::cout << '\n';
        }
    }

    void build(int _n, int _answer, int _t, int _p, int _num)
    {
        std::cout << "begin with: " << _num << '\n';
        initialize(_n, _answer);
        makeSplit();
        std::cout << "make prime split\n";
        makePrimeSplit(false);

        std::cout << "build: " << answer << "\n";
        for (int i = 0 ; i < answer ; ++i)
        {
            buildComponent(i, _t, _p);
        }

        print(_num);
        std::cout << "done with: " << _num << '\n';
    }

    void build3(int _n, int _answer, int _t, int _p, int _num)
    {
        std::cout << "begin with: " << _num << '\n';
        initialize(_n, _answer);
        makeSplit();
        std::cout << "make prime split\n";
        makePrimeSplit(true);
        
        std::cout << "build: " << answer << "\n";
        for (int i = 0 ; i < answer ; ++i)
        {
            buildComponent(i, _t, _p);
        }

        print(_num);
        std::cout << "done with: " << _num << '\n';
    }

    void build2(int _n, int _answer, int _t, int _p, int _num)
    {
        std::cout << "                  CASLLLLLL begin with: " << _num << ' ' << _answer << '\n';
        initialize(_n, _answer);
        makeSplit();

        std::cout << "make prime split\n";

        std::cout << "build: " << answer << "\n";
        int ptr = 0;

        for (int i = 0 ; i < answer ; ++i)
        {
            ptr = buildComponent2(i, ptr, _t, _p);
        }
        print(_num);
        std::cout << "done with: " << _num << '\n';
    }

    void buildRandom(int _n, int _num)
    {
        s.resize(n);
        if (!onlyPrimes[ID])
        {
            for (int i = 0 ; i < n ; ++i)
            {
                s[i] = rnd.next(maxA[ID]) + 1;
            }
        } else
        {
            for (int i = 0 ; i < n ; ++i)
            {
                s[i] = primes[rnd.next(primes.size())];
            }
        }

        print(_num);
    }

    std::string testNAME(int num)
    {
        std::string first; first += num / 10 + '0';
        std::string second; second += num % 10 + '0';
        return TASK_NAME + "." + first + second + ".in";
    }

    std::string testSOL(int num)
    {
        std::string first; first += num / 10 + '0';
        std::string second; second += num % 10 + '0';
        return TASK_NAME + "." + first + second + ".sol";
    }

    void print(int num)
    {
        std::cout << "      done with: " << num << '\n';
        std::ofstream in(testNAME(num));
        std::ofstream sol(testSOL(num));

        in << n << '\n';
        for (int i = 0 ; i < n ; ++i)
        {
            in << s[i];
            if (i + 1 != n) in << ' ';
        }

        in << '\n';
        sol << answer << '\n';
        in.close();
        sol.close();
    }
};

Test test;
int main(int argc, char **argv)
{
    registerGen(argc, argv, 1);
    std::cin >> ID;
    sieve(maxA[ID]);

    Test test;
    test.build(randomN(), myLog(maxN[ID]) + rnd.next(5) - 2, -3, 0, from[ID]);
    test.build(maxN[ID], myLog(maxN[ID]) + rnd.next(5) - 2, 15, 0, from[ID] + 1);
    test.build(maxN[ID], 1, 1, 10, from[ID] + 2);

    std::cout << "  sqrt is: " << sqrt(maxN[ID]) << '\n';
    if (!onlyPrimes[ID]) 
    {
        test.build2(randomN(), sqrt(maxN[ID]) + rnd.next(5) - 2, -3, 0, from[ID] + 3);
    } else test.build(randomN(), (rnd.next(3) + 1) * sqrt(maxN[ID]) + rnd.next(5) - 2, -3, 0, from[ID] + 3);

    test.build(maxN[ID], (rnd.next(3) + 1) * sqrt(maxN[ID]) + rnd.next(5) - 2, 15, 0, from[ID] + 4);
    test.build(maxN[ID], (rnd.next(3) + 1) * sqrt(maxN[ID]) + rnd.next(5) - 2, 1, 10, from[ID] + 5);

    if (ID != 5)
    {
        test.build3(maxN[ID], (rnd.next(3) + 1) * (maxN[ID] / myLog(maxN[ID])) + rnd.next(5) - 2, -3, 0, from[ID] + 6);
        test.build(maxN[ID], (rnd.next(3) + 1) * (maxN[ID] / myLog(maxN[ID])) + rnd.next(5) - 2, 8, 0, from[ID] + 7);
        test.build(maxN[ID], maxN[ID], 1, 10, from[ID] + 8);
        test.buildRandom(randomN(), from[ID] + 9); 
    } else
    {
        test.build(randomN(), (rnd.next(3) + 1) * (maxN[ID] / myLog(maxN[ID])) / 4 + rnd.next(5) - 2, -3, 0, from[ID] + 6);
        test.build(maxN[ID], (rnd.next(3) + 1) * (maxN[ID] / myLog(maxN[ID])) / 4 + rnd.next(5) - 2, 3, 0, from[ID] + 7);
        test.build(maxN[ID], (rnd.next(3) + 1) * (maxN[ID] / myLog(maxN[ID])) / 4, 1, 10, from[ID] + 8);
        test.buildRandom(randomN(), from[ID] + 9); 
    }

    return 0;
}