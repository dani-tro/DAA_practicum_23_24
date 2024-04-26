# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int p[maxn];
int r[maxn];
int myfind (int a)
{
    if (p[a] == -1) return a;
    return p[a] = myfind(p[a]);
}
void uni (int a, int b){
    a = myfind(a);
    b = myfind(b);
    if (a == b) return ;
    if (r[a] < r[b]){
        p[a] = b;
    } else if (r[a] > r[b]){
        p[b] = a;
    } else {
        p[a] = b;
        r[b] ++ ;
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset (p, -1, sizeof(p));
    memset (r, 0, sizeof(r));
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> u >> v;
        uni (u, v);
    }
    int q, t;
    cin >> q;
    for (int i = 1; i <= q; i++){
        cin >> t >> u >> v;
        if (t == 1){
            cout << (myfind(u) == myfind(v));
        } else {
            uni(u,v);
        }
    }
    cout << endl;
}
