#include<bits/stdc++.h>
using namespace std;

const int MAXA = 1e6;
const int MAXN = 1e6;

int n, k, A[MAXN + 5], min_div[MAXA + 5], cnt[MAXA + 5], ans = 1;

void sieve(){
    for(int d = 2; d <= MAXA; d ++){
        if(min_div[d]) continue;
        for(int k = d; k <= MAXA; k += d){
            if(min_div[k] == 0){
                min_div[k] = d;
            }
        }
    }
}

void add(int x){
    while(x != 1){
        int d = min_div[x];
        while(x % d == 0){
            x /= d;
        }
        ++ cnt[d];
        if(cnt[d] == k){
            ans = max(ans, d);
        }
    }
}

void rem(int x){
    while(x != 1){
        int d = min_div[x];
        while(x % d == 0){
            x /= d;
        }
        -- cnt[d];
    }
}

int main(){
    sieve();
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> A[i];
    }
    for(int i = 1; i <= k; i ++){
        add(A[i]);
    }
    for(int i = 1, j = k + 1; j <= n; i ++, j ++){
        rem(A[i]);
        add(A[j]);
    }
    cout << ans << endl;
}

