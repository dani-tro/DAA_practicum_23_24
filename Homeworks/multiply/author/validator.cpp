#include<iostream>
#include<assert.h>
#include<vector>
#define MAXN 500000
#define MAX 10000000
using namespace std;
int minp[MAX+1],prev1[MAX+1];
int cnt;
int p[MAX+1],rank1[MAX+1];
int root (int v) {
    if (v==p[v]) return v;
    return p[v]=root(p[v]);
}
void merge1 (int u, int v) { //cout << u << " " << v << endl ;
    u=root(u); v=root(v);
    if (u==v) return ;
    cnt--;
    if (rank1[u]>rank1[v]) swap(u,v);
    p[u]=v;
    if (rank1[u]==rank1[v]) rank1[v]++;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i=2; i<=MAX; i++) {
        if (minp[i]!=0) continue;
        for (int j=i; j<=MAX; j+=i) {
            minp[j]=i;
        }
    }

    int n;
    assert(cin >> n );
    assert((1<=n)&&(n<=MAXN));
    cnt=n;
    for (int i=0; i<n; i++) {
        int num;
        assert(cin >> num );
        assert((1<=num)&&(num<=MAX));
        if (num==1) continue;
        if (p[num]!=0) cnt--;
        else {
            p[num]=num;
            int tmp=num;
            for (;;) {
                if (tmp==1) break;
                int p=minp[tmp];
                if (prev1[p]!=0) merge1(prev1[p],num);
                prev1[p]=num;
                for (;;) {
                    if (tmp%p!=0) break;
                    tmp/=p;
                }
            }
        }
    }
    char temp; assert(!(cin >> temp ));
    cout << cnt ;
    cout << endl ;
    return 0;
}
