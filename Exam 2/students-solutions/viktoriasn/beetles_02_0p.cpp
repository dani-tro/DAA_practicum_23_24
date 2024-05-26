#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAXN = 100000;

int n;
vector<pair<long long, long long>> graph[MAXN];
vector<pair<int, int>> coords;

bool added[MAXN];

long long calc(int xi, int xj, int yi, int yj) {
    
    
    return pow(xi - xj, 2) + pow(yi - yj, 2);

}


int main() {

    cin >> n;
    fill(added, added + n + 1, false);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coords.push_back({ x, y });
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n ; j++) {
            if (i != j) {
                graph[i].push_back({ j, calc(coords[i - 1].first, coords[j - 1].first, coords[i - 1].second, coords[j - 1].second) });
               // graph[j].push_back({ i, calc(coords[j-1].first, coords[i-1].first, coords[j-1].second, coords[i-1].second) });
            }
        }
    }
    long long sum = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>> > pq;
    pq.push({ 0, 1 });
    for (pair<long long, long long> ver : graph[1]) {
        pq.push({ ver.second, ver.first });
        cout << ver.second << "w" << ver.first;
    }
   // cout << pq.size();
    added[1] = true;
    while (!pq.empty()) {
        
        pair<long long, long long> curr = pq.top();
        pq.pop();
       cout << "w" << curr.first << "v" << curr.second << endl;
        if (!added[curr.second]) {
            cout << "curr" << curr.first;
            sum += curr.first;
            cout << sum<<endl;
            added[curr.second] = true;
            for (pair<long long, long long> ver : graph[curr.second]) {
                pq.push({ ver.second  ,ver.first });
            }
        }
    }

    cout << sum << endl;
    return 0;
}

