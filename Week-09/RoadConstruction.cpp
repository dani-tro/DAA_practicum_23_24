# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int p[maxn];
int r[maxn];
int numComponents;
int sz[maxn];
int maxSize;
int myfind (int a)
{
    if (p[a] == -1) return a;
    return p[a] = myfind(p[a]);
}
void uni (int a, int b){
    a = myfind(a);
    b = myfind(b);
    if (a == b) return ;
    numComponents -- ;
    if (r[a] < r[b]){
        p[a] = b;
        sz[b] += sz[a];
    } else if (r[a] > r[b]){
        p[b] = a;
        sz[a] += sz[b];
    } else {
        p[a] = b;
        r[b] ++ ;
        sz[b] += sz[a];
    }
    maxSize = max (maxSize, sz[a]);
    maxSize = max (maxSize, sz[b]);
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset (p, -1, sizeof(p));
    memset (r, 0, sizeof(r));
    fill (sz, sz + maxn, 1);
    int n, m, u, v;
    cin >> n >> m;
    numComponents = n;
    maxSize = 0;
    for (int i = 1; i <= m; i++){
        cin >> u >> v;
        uni (u, v);
        cout << numComponents << " " << maxSize << endl;
    }

    cout << endl;
}
