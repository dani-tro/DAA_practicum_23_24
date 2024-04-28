#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> dists;
void input(){
    cin >> n >> k;
    dists.resize(n-1);
    for(int i = 0; i < n-1; i++){
        cin >> dists[i];
    }
}

long long getMax(){
    long long sum = 0;
    for(int i = 0; i < n-1; i++){
        sum+= dists[i];
    }
    return sum;
}

bool ok(long long curr){
    int tvs = 0;
    long long currSum=0;
    for(int i = 0; i < n-1;i++){
        if(currSum+dists[i]<=curr){
            currSum+=dists[i];
        } else {
            currSum=0;
            tvs++;
        }
    }

    return tvs<=k && (currSum<=curr);
}

long long solve(){
    long long l = 0, r = getMax(), ans = 0;
    while(l<=r){
        long long mid = (r+l)/2;
        if(ok(mid)){
            r = mid-1;
            ans = mid;
        } else {
            l = mid+1;
        }

    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    cout << solve();
    return 0;
}
