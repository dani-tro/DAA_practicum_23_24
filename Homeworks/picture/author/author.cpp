#include <iostream>
using namespace std;

int a[5012][5012];
int pref[5012][5012];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m=1;
    int k;
    cin>>n>>k;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            cin>>a[i][j];
            pref[j+1][i] = pref[j][i]+a[i][j];
        }
    }
    for (int i=0; i+m<=n; ++i){
        //cout<<"i: "<<i<<endl;
        int sum=0;
        for (int j=0; j<m; ++j){
            sum += pref[i+m][j]-pref[i][j];
        }
        for (int j=m; j<=n; ++j){
            //cout<<"j: "<<j<<endl;
            while(sum<k && j<=n && i+m<=n){
                ++m;
                sum += pref[i+m][j] - pref[i][j];
                for (int l=j-m; l<j; ++l) sum += a[l][i+m-1];
                ++j;
            }
            //cout<<"j, m: "<<j<<" "<<m<<endl;
            if (i+m>n || j>=n) break;
            sum -= pref[i+m][j-m] - pref[i][j-m];
            sum += pref[i+m][j] - pref[i][j];
        }
    }
    if (m>n) cout<<-1<<endl;
    else cout<<m<<endl;
    return 0;
}
