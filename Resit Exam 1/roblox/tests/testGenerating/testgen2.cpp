// не го чети, моля

#include <bits/stdc++.h>
typedef long long llong;
using namespace std;
const llong maxn = 5e5+10, inf = 1e9;

ifstream fin("constraints.txt");
ofstream fout;

int n, m, k, ans, current;
int a[maxn];

std::vector < int > v;
void build() {

    std::cout << "testgen2\n";
    bool bl;
    llong minN, maxN, minK, maxK, maxNum, minNum;
    fin >> minN >> maxN >> minK >> maxK >> bl;// >> minNum >> maxNum;

    int test = 0;    

    k = 1;
    n = rand()%(maxN - minN + 1) + minN;
    int size = rand()%(maxK - minK + 1) + minK;
    maxNum = 1001;
    
    int left = n;
    for (int i = 1 ; i <= size-1 ; ++i)
    {
        int take = 1;;
        v.push_back(take);
        left -= take;
    }
    v.push_back(left);

    int sum = 0;
    for (int i : v) sum += i;
    std::cout << n << ' ' << sum << '\n';
    std::cout << std::flush;

    int to = 1;
    for (int i = 0 ; i < v.size() ; ++i)
    {
        for (int j = 1 ; j <= v[i] ; ++j)
        {
            if ((i % 2) == bl) a[to++] = 0;
            else a[to++] = rand()%(maxNum - 1) + 1;
            
        }
    }

    assert(to == n+1);

    fout << n << ' ' << k << '\n';
    for (int i = 1 ; i <= n ; ++i) 
    {
        if (i != 1) fout << ' ';
        fout << a[i];
    }
    fout << '\n';

    fout.close();
    fin.close();

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