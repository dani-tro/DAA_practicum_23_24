#include<iostream>
#include<algorithm>
#include<assert.h>
#include<tuple>
#define MAXN 100000
#define MAXM 1000000
using namespace std;
int a[MAXN],from[MAXM],to[MAXM];
int open[MAXN],close[MAXN];
tuple <int, int, int> segs[MAXN];
long long int pref[MAXN];
int main () {
    long long int n,m,k,i;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    assert(cin >> n >> m >> k );
    assert((n>=1)&&(n<=1e5));
    assert((m>=1)&&(m<=1e6));
    assert((k>=0)&&(k<=1e12));
    for (i=0; i<n; i++) {
        assert(cin >> a[i] );
        assert((a[i]>=0)&&(a[i]<=1e7));
    }
    for (i=0; i<m; i++) {
        assert(cin >> from[i] >> to[i] );
        assert((from[i]>=1)&&(from[i]<=to[i])&&(to[i]<=n));
        from[i]--; to[i]--;
        open[from[i]]++;
        close[to[i]]++;
    }
    char dummy; assert(!(cin >> dummy ));
    int opened=0;
    for (i=0; i<n; i++) {
        opened+=open[i];
        segs[i]={opened, a[i], i};
        opened-=close[i];
    }
    sort(segs,segs+n);
    for (i=n-1; i>=0; i--) {
        int ind=get<2>(segs[i]);
        if (a[ind]>k) {
            a[ind]-=k;
            k=0;
            break;
        }
        k-=a[ind];
        a[ind]=0;
    }
    pref[0]=0;
    for (i=0; i<n; i++) {
        pref[i+1]=pref[i]+a[i];
    }
    long long int ans=0;
    for (i=0; i<m; i++) {
        ans+=pref[to[i]+1]-pref[from[i]];
    }
    cout << ans ;
    cout << endl ;
    return 0;
}
