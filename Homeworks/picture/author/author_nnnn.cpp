#include <iostream>
using namespace std;

int n, m=1;
long long k;

int a[5012][5012];

bool check(int i, int j){
    long long sum = 0;
    for (int ii=i; ii<i+m; ++ii){
        for (int jj=j; jj<j+m; ++jj){
            sum += a[ii][jj];
            if (sum >= k) return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            cin>>a[i][j];
        }
    }
    for (int i=0; i<n-m+1; ++i){
        for (int j=0; j<n-m+1; ++j){
            while(!check(i, j) && i<n-m+1 && j<n-m+1){
                ++m;
            }
        }
    }
    if (m>n) cout<<-1<<endl;
    else cout<<m<<endl;
    return 0;
}
