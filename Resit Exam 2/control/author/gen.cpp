#include <bits/stdc++.h>
#include <unistd.h>
#define D(x) cout << __LINE__ << " " << #x << " = " << (x) << endl;
#define endl '\n'
using namespace std;

const string PROBLEM_NAME = "pairs";
const int NUM_TESTS = 20;

long long getRandInt16() {
    return rand() % 32768;
}
long long getRandInt32() {
    return getRandInt16()*(1LL << 16) + getRandInt16();
}
long long getRandInt64() {
    return getRandInt32()*(1LL << 32) + getRandInt32();
}

long long getRandom(long long minV, long long maxV) {
    if(minV == maxV) return minV;
    else return getRandInt64() %(maxV - minV) + minV;
}

bool getChance(double p) {
    return (rand()%1000 / 1000.0) < p;
}

double getTimeSec() {
    return clock() / (double)CLOCKS_PER_SEC;
}

void gen_test(int test_id) {
    cerr << "test " << test_id << endl;
    string test_num_str;
    if (test_id < 10 ) test_num_str = "0";
    test_num_str += to_string(test_id);

    ofstream f(PROBLEM_NAME + "." + test_num_str + ".in");
    double time_start = getTimeSec();
    
    int n = getRandom(800'000, 1'000'000);
    int m = getRandom(n*0.5, n*0.9);

    f << n << " " << m << endl;

    vector<pair<int, int>> v;
    int start = getRandom(0, n-m);
    int others = 10;

    for (int i = 0; i < m - others; i++) {
        v.push_back({start+i, start+i+1});
    }

    for (int i = 0; i < others; i++) {
        v.push_back({getRandom(0, start), getRandom(0, start)});
    }

    random_shuffle(v.begin(), v.end());
    for(auto [x, y] : v) f << x << " " << y << endl;

    f.close();
    cerr << "time: " << getTimeSec() - time_start << endl;
}

void gen_all() {
    for (int i = 12; i <= NUM_TESTS; i++) {
        gen_test(i);
    }
}

int main() {
    gen_all();
    return 0;
}
