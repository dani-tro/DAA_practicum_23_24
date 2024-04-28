#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

long long k,n,num, longest_seq,current_last, arr[MAX];

void solve(){
    cin >>  n >> k;
    //longest_seq=0;
    for(int i = 1; i <=n; i++){
        cin >> arr[i];
    }

    sort(arr+1, arr+n+1);

    for(int i = 1; i <= n-longest_seq;i++){
        current_last=i;
        while(arr[current_last] - arr[i] <= k && current_last <=n){
            current_last++;
        }
        if(longest_seq < current_last - i){
            longest_seq=current_last-i;
        }
    }
    cout << longest_seq << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
