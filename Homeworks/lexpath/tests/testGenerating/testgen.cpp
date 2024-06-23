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
const int MAXN = 500000 + 10;
const int MAXNUM = 1e7 + 10;
const int INF = 1e9;

int n, m, answer;
int t, letters;
char perm[26];
struct Edge
{
    int from, to;
    char cost;
};

std::vector <Edge> edges;
std::vector <int> g[MAXN];
std::vector <int> byDep[MAXN];
std::unordered_set <llong> s;

void addEdge(int u, int v, char c)
{
    assert(u != v);
    assert(!s.count(1LL * n * u + v));
    edges.push_back({u, v, c});
    s.insert(1LL * n * u + v);
    s.insert(1LL * n * v + u);
    g[u].push_back(v);
    g[v].push_back(u);
}

bool valid(int u, int v)
{
    return u != v && !s.count(1LL * n * u + v);
}

int max;
void dfs(int node, int par, int dep)
{
    max = std::max(max, dep);
    byDep[dep].push_back(node);
    for (const int &u : g[node])
    {
        if (u != par)
        {
            dfs(u, node, dep + 1);
        }
    }
}

int main(int argc, char **argv)
{
    registerGen(argc, argv, 1);

    std::ifstream fin("constraints.txt");
    std::string filename;
    fin >> filename >> n >> m >> answer >> t >> letters;

    std::iota(perm, perm + 26, 'a');
    if (letters != 1)
    {
        shuffle(perm, perm + 26);
    }

    bool isEdgeCase = false;
    if (answer > 0)
    {
        std::vector <int> part = rnd.partition(answer - 1, n - 2, 1);
        std::vector <int> order(n - 2);
        std::iota(order.begin(), order.end(), 2);
        shuffle(order.begin(), order.end());
        
        int pos = 0;
        for (int i = 0 ; i < part.size() ; ++i)
        {
            for (int j = 0 ; j < part[i] ; ++j)
            {
                byDep[i + 1].push_back(order[pos++]);
            }
        }

        byDep[0].push_back(1);
        byDep[answer].push_back(n);

        for (int dep = 1 ; dep <= answer ; ++dep)
        {
            assert(byDep[dep].size());
            for (const int &u : byDep[dep])
            {
                addEdge(byDep[dep - 1][rnd.wnext(byDep[dep - 1].size(), t)], u, perm[rnd.next(letters)]);
            }
        } 
    } else
    {
        isEdgeCase = true;
        answer = -answer;
        std::vector <int> order(n - 2);
        std::iota(order.begin(), order.end(), 2);
        shuffle(order.begin(), order.end());

        int pos = 0;
        int cntSplits = 0;
        for (int i = 2 ; i < answer ; i += 2)
        {
            cntSplits++;
            byDep[i].push_back(order[pos++]);
        }
        
        cntSplits += (answer % 2 == 0);
        std::vector <int> part = rnd.partition(cntSplits, (int)order.size() - pos, 1);
        for (int i = 1 ; i < answer ; i += 2)
        {
            for (int j = 0 ; j < part[i / 2] ; ++j)
            {
                byDep[i].push_back(order[pos++]);
            }
        }

        byDep[0].push_back(1);
        byDep[answer].push_back(n);

        for (int dep = 1 ; dep <= answer ; ++dep)
        {
            assert(byDep[dep].size());
            for (const int &u : byDep[dep])
            {
                for (const int &v : byDep[dep - 1])
                {
                    addEdge(u, v, perm[rnd.next(letters)]);
                }
            }
        } 
    }

    std::cout << "HEEEEEEEEREEEEEEEEEEEEEEEEEEEEEE\n";
    while (edges.size() < m)
    {
        int type = rnd.next(10);
        if (isEdgeCase || type == 0)
        {
            bool found = false;
            while (!found)
            {
                int dep = rnd.next(answer);
                for (int tries = 0 ; tries < 10 ; ++tries)
                {
                    int u = byDep[dep][rnd.next(byDep[dep].size())];
                    int v = byDep[dep][rnd.next(byDep[dep].size())];
                    if (valid(u, v))
                    {
                        addEdge(u, v, perm[rnd.next(letters)]);
                        found = true;
                        break;
                    }
                }
            }
        } else
        {
            bool found = false;
            while (!found)
            {
                int dep = rnd.next(answer - 1);
                for (int tries = 0 ; tries < 10 ; ++tries)
                {
                    int u = byDep[dep][rnd.next(byDep[dep].size())];
                    int v = byDep[dep + 1][rnd.next(byDep[dep + 1].size())];
                    if (valid(u, v))
                    {
                        addEdge(u, v, perm[rnd.next(letters)]);
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    
    assert(edges.size() == m);
    std::ofstream fout(filename);
    shuffle(edges.begin(), edges.end());
    for (Edge &e : edges)
    {
        if (rnd.next(2) == 0)
        {
            std::swap(e.from, e.to);
        }
    }
    
    fout << n << ' ' << m << '\n';
    for (const Edge &e : edges)
    {
        fout << e.from << ' ' << e.to << ' ' << e.cost << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}