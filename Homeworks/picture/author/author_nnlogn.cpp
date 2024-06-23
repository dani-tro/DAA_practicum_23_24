#include <iostream>
using namespace std;

int n;
int k;
int a[5012][5012];
int pref[5012][5012];

bool check(int m){
    for (int i=0; i<=n-m; ++i){
        int sum = 0;
        for (int j=0; j<m; ++j){
            sum += pref[j][i+m] - pref[j][i];
        }
        for (int j=m; j<=n; ++j){
            if (sum < k) return 0;
            sum -= pref[j-m][i+m] - pref[j-m][i];
            sum += pref[j][i+m] - pref[j][i];
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    int F, A, B, M; cin >> F >> A >> B >> M;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
           	F = a[i][j] = (F * A + B) % M;
            pref[i][j+1] = pref[i][j] + a[i][j];
        }
    }
    int l=0, r=n+1;
    while(r-l>1){
        int mid = (l+r)/2;
        if (check(mid)) r=mid;
        else l=mid;
    }
    if (r==n+1) cout<<-1<<endl;
    else cout<<r<<endl;
    return 0;
}
