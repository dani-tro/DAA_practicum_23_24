#include <bits/stdc++.h>

using namespace std;

#define MAX 100100


pair<int,long long> arr[MAX];
auto cmp = [](int left, int right) { return arr[left].first*arr[left].second < arr[right].first*arr[right].second;};
priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
int n,m, l, r, value, index;
long long decreases;

void dec(){
    index=pq.top();
    pq.pop();
    if (arr[index].second == 0){
        if(!pq.empty())
            dec();
    }else{
        arr[index].second--;
    }
    pq.push(index);
}

void solve(){
    cin >> n >> m >> decreases;

    for(int i = 1; i <= n; i++){
        cin >> value;
        arr[i] = {0, value};
    }

    for(int i = 1; i <= m;i++){
        cin >> l >> r;
        for(int j = l; j <=r; j++){
            arr[j].first++;
        }
    }
    for(int i = 1; i <=n; i++){
        pq.push(i);
    }

    for(int i = 1; i <=decreases; i++){
        dec();
    }
    long long sum = 0;
    while(!pq.empty()){
        sum+=arr[pq.top()].first*arr[pq.top()].second;
        pq.pop();
    }
    cout << sum << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
