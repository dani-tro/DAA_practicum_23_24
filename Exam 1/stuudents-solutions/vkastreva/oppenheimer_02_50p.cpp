#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
long long n, k;
vector<long long> crit;
void input(){
    cin >> n >> k;
    crit.resize(n);
    for(long long i = 0; i < n; i++){
        cin >> crit[i];
    }
}

long long solve(){
    sort(crit.begin(),crit.end());

    long long l = 0, r = 1;
    long long maxLen = 1;
    while(r < crit.size() && crit[r]-crit[l]<=k){
        r++;
        maxLen++;
    }
    long long currMax = maxLen;
    while(l < r && r < crit.size()){
        if(crit[r]-crit[l]>k){
            l++;
            currMax--;
        } else {
            r++;
            currMax++;
            maxLen = max(maxLen, currMax);
        }
    }
    return maxLen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    cout << solve();
    return 0;
}
