#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long


using namespace std;

const int N = 100005;

vector<int> sz(N);
vector<int> d(N);
vector<int> par(N);

ll cost;

struct Edge
{
    ll u, v;
    unsigned ll c;

    bool operator<(const Edge& o) const {
        return c < o.c;
    }
};


vector<pair<ll, ll>> v;
vector<Edge> edges;

int fnd(int x) {
    if (par[x] == -1)
    {
        return x;
    }

    return par[x] = fnd(par[x]);
}

int cmpCnt = 0;

void uni(int a, int b) {
    a = fnd(a);
    b = fnd(b);

    if (a != b)
    {
        if (d[a] > d[b])
        {
            par[b] = a;
        } else {
            par[a] = b;
            if (d[a] == d[b])
            {
                d[b] ++;
            }
            
        }


        
    }
    
}

int x, y;

int main() {
    fill(d.begin(), d.end(), 0);
    fill(par.begin(), par.end(), -1);

    int n;
    cin >> n;
    
    cmpCnt = n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        
        v.push_back({x, y});    
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            unsigned ll a = v[j].first - v[i].first;
            a *= a;

            unsigned ll b = v[j].second - v[i].second;
            b *= b;

            edges.push_back({i, j, a + b});
        }
    }

    sort(edges.begin(), edges.end());
    
    int i = 0;
    while (i < edges.size())
    {
        Edge edge = edges[i++];
        
        if (fnd(edge.u) != fnd(edge.v))
        {
            cmpCnt--;
            uni(edge.u, edge.v);

            cost += edge.c;
        }
            
    }

    cout << cost << '\n';
        
}