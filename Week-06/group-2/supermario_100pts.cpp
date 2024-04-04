#include<bits/stdc++.h>
using namespace std;


int main(){
    long long n, s; cin >> n >> s;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long sum = 0;
    for(int i = 0; i < n; i ++){
        long long p; cin >> p;
        p -= i * s;
        if(!pq.empty() && (p - pq.top()) > 0){
            sum -= pq.top(); pq.pop();
            sum += p;
            pq.push(p);
        }
        pq.push(p);
    }
    cout << sum << endl;
}
