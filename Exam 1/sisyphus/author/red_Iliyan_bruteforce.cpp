#include<iostream>
#include<algorithm>
#include<assert.h>
#include<tuple>
#define MAXN 100000
#define MAXM 1000000
using namespace std;
int a[MAXN],from[MAXM],to[MAXM],n,m;
long long int min1=1e18;
void brute_force (int ind, long long int k) {
    if (ind==n) {
        long long int sum=0;
        for (int i=0; i<m; i++) {
            for (int j=from[i]; j<=to[i]; j++) {
                sum+=a[j];
            }
        }
        min1=min(min1,sum);
        return ;
    }
    for (long long int i=0; i<=k; i++) {
        if (a[ind]<i) break;
        a[ind]-=i;
        brute_force(ind+1,k-i);
        a[ind]+=i;
    }
}
int main () {
    long long int k,i;
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
        from[i]--; to[i]--;
    }
    char dummy; assert(!(cin >> dummy ));
    brute_force(0,k);
    cout << min1 ;
    cout << endl ;
    return 0;
}
