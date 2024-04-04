#include<bits/stdc++.h>
using namespace std;


int main(){
    long long n, k, f, a, b, m;
    cin >> n >> k >> f >> a >> b >> m;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    for(int i = 1; i <= n; i ++){
        while(!pq.empty() && pq.top().second + k < i){
            pq.pop();
        }
        long long dp = f + pq.top().first;
        pq.push({dp, i});
        f = (f * a + b) % m;
    }
    while(!pq.empty() && pq.top().second + k < n + 1){
        pq.pop();
    }
    cout << pq.top().first << endl;
}

