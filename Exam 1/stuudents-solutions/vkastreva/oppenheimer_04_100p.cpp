#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n, k;
vector<int> crit;
void input(){
    cin >> n >> k;
    crit.resize(n);
    for(int i = 0; i < n; i++){
        cin >> crit[i];
    }
}

int solve(){
    sort(crit.begin(),crit.end());
    if(crit.size() == 1) return 1;
    int l = 0, r = 1;
    int maxLen = 1;
    while(r < crit.size() && crit[r]-crit[l]<=k){
        r++;
        maxLen++;
    }
    int currMax = maxLen;
    while(l <= r && r < crit.size()){
        if(crit[r]-crit[l]>k){
            l++;
            currMax--;
        } else {
            r++;
            currMax++;
            maxLen = max(maxLen, currMax);
        }
    }
    //cout << l << " " << r << endl;
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
