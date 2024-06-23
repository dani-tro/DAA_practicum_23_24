#include <bits/stdc++.h>
typedef long long llong;
using namespace std;
const llong maxn = 1e7+10, inf = 1e18;

ifstream fin("constraints.txt");
ofstream fout;

bool bigger;
llong a[maxn], n, k, len;
llong prefixSquared[maxn];
llong prefix[maxn];

inline llong calcSum(int l, int r)
{
    --l;
    llong sum = (prefix[r] - prefix[l]);
    llong sum2 = (prefixSquared[r] - prefixSquared[l]);
    if (sum >= (2*(inf-bigger) + sum2) / sum + 1) return -1;
    return (sum*sum - sum2) / 2;
}


llong longRand()
{
    llong a = rand();
    llong b = rand();
    return (a << 32) + b;
}

void build() {

    llong minN, maxN;
    llong minLen, maxLen;
    const llong maxNum = 1e15;
    
    fin >> minN >> maxN;
    fin >> minLen >> maxLen;
    fin >> bigger;
    n = 10000000;
    k = 1e18;

    for (int i = 1 ; i <= n ; ++i) a[i] = 1000;
    std::ios_base :: sync_with_stdio(0);
    fout.tie(nullptr);

    fout << n << ' ' << k <<'\n';
    for (int i = 1 ; i <= n ; ++i)
    {
        if (i != 1) fout << ' ';
        fout << a[i];
    }
    fout << '\n';
    fin.close();
    fout.close();
}

int main (int argc, char** argv) 
{
    int seed = time(nullptr);
    srand(seed);
    cout << "seed: " << seed << '\n';

    if (argc != 2) 
    {
        cout << "There should be exactly one argument - the name of the in file!\n";
        return 0;
    }

    fout.open(argv[1]);
    build();
    return 0;
}