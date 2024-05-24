# include <bits/stdc++.h>
using namespace std;

#define MAX 110000

int n, m, a, b;

pair<int, int> h[MAX];

struct edge
{
   int a, b, c;
   bool operator<(const edge& other)
   {
       return c < other.c;
   }
};

vector<edge> e;

int par[MAX], d[MAX], ans;

int find(int a)
{
    if(par[a] == 0)return a;
    return par[a] = find(par[a]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if(d[a] > d[b])
    {
        par[b] = a;
    }
    else
    {
        par[a] = b;
        if(d[a] == d[b])d[b]++;
    }
    return;
}

void kruskal()
{
    sort(e.begin(), e.end());

    for(edge l : e)
    {
        if(find(l.a) == find(l.b))continue;
        uni(l.a, l.b);
        ans += l.c;
    }
    return;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> h[i].first;
        h[i].second = i;
    }

    for(int i = 0; i < m; i++)
    {

        cin >> a >> b;
        e.push_back({a, b, 0});
    }

    sort(h + 1, h + n + 1);
    for(int i = 1; i < n ; i++)
    {
        e.push_back({h[i].second, h[i + 1].second, h[i + 1].first - h[i].first});
    }

    kruskal();

    cout << ans << endl;
}
