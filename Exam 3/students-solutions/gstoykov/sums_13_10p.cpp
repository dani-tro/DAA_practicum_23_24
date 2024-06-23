#include <bits/stdc++.h>
using namespace std;
const long long SIZE = 105;
long long arr[SIZE];
long long dp [SIZE][SIZE];
long long n,a,b;
set<long long> s;
long long counter = 0;

void f(int ind,int sum) {
    if (ind >=n) {
        return ;
    }
    if (sum > b) {
        return ;
    }
    if (sum>=a && sum <=b) {
        s.insert(sum);
    }
    int curr = 0;
    for (size_t i = ind; i < n; i++){
        f(i,sum + arr[i]);
    }
    
}
int main() {
    #define endl '\n'
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b;
    for (size_t i = 0; i < n; i++) {
        long long d;
        cin >> d;
        arr[i] = d;
    }
    f(0,0);
   
    
    cout << s.size();
    
}
