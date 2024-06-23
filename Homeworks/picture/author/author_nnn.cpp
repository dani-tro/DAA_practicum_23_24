#include <iostream>
using namespace std;

int n, k;
int a[5012][5012];
int pref[5012][5012];

bool check(int m){
    int minsum = m*m*51;
    for (int i=0; i+m-1<n; ++i){
        int sum = 0;
        for (int j=0; j<n; ++j){
            sum += pref[j][i+m] - pref[j][i];
            if (j-m >= 0) sum -= pref[j-m][i+m] - pref[j-m][i];
            //cout<<i<<" "<<j<<" "<<sum<<endl;
            if (j >= m-1) minsum = min(minsum, sum);
        }
    }
    return minsum >= k;
}

int main(){
    cin>>n>>k;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            cin>>a[i][j];
            pref[i][j+1] = pref[i][j] + a[i][j];
        }
    }
    int minm = n+1;
    for (int i=1; i<=n; ++i){
        if (check(i)) minm = min(minm, i);
    }
    if (minm > n) cout<<-1<<endl;
    else cout<<minm<<endl;
    return 0;
}
