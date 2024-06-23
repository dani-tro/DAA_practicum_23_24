#include <iostream>
using namespace std;

int n;
long long k;

int a[5012][5012];

bool check(int m, int i, int j){
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
    for (int m=0; m<=n; ++m){
        bool possible = true;
        for (int i=0; i<n-m+1 && possible; ++i){
            for (int j=0; j<n-m+1 && possible; ++j){
                if (!check(m, i, j)) possible = false;
            }
        }
        if (possible){
            cout<<m<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
