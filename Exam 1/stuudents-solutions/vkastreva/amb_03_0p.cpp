#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n, k;
vector<int> dists;
void input(){
    cin >> n >> k;
    n--;
    dists.resize(n);
    for(int i = 0; i < n; i++){
        cin >> dists[i];
    }
}

long long getMax(){
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += dists[i];
    }
    return sum;
}

bool ok(long long dist){
    long long tvs = 0;
    long long currSum = 0;
    int i = 0;
    while(i < dists.size() && tvs < k){
        if(currSum+dists[i]<=dist){
            currSum+=dists[i];
        } else {
            tvs++;
            currSum = dists[i];
        }
        i++;
    }

    //currSum = 0;
    for(int j = i; j < n; j++){
        if(currSum+dists[j] > dist) return false;
        else currSum+=dists[j];
    }
    return true;
}

long long solve(){
    long long l = 0, r = getMax();
    long long ans;
    while(l<=r){
        long long mid = l + (r-l)/2;
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
    cout << solve() << endl;
    return 0;
}
