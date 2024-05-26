#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n, m, k, q, a, b, c;
//to, cost
vector<pair<int, int>> gr[MAXN];
int d[MAXN];
bool visited[MAXN];
vector<int> places;
vector<int> ans;
//dist, to
priority_queue<pair<int, int>> pq;

void dijkstra(int v){
    d[v] = 0;
    pq.push({d[v], v});

    while(!pq.empty()) {
        int curr = pq.top().second;
        // cout << curr << " neighbours:  ";
        pq.pop();
        if(visited[curr]) continue;
        visited[curr] = true;

        for(pair<int, int> p : gr[curr]) {
            // cout << p.second << "  ";
            if(d[p.second] > d[curr] + p.first) {
                d[p.second] = d[curr] + p.first;
                pq.push({-d[p.second], p.second});
            }
        }
        // cout << endl;
    }
    // cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        gr[a].push_back({c, b});
        gr[b].push_back({c, a});
    }

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> a;
        places.push_back(a);
    }

    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> a;
        fill(visited, visited + n, false);
        fill(d, d + n, INT_MAX);
        dijkstra(a);

        // cout << "DISTANCES   ";
        // for(int f = 0; f < n; f++) {
        //     cout << d[f] << "  ";
        // }
        // cout << endl;

        // cout << "_________________________________________" << endl;
        int min = INT_MAX;
        for(int p : places) 
            if(d[p] < min) min = d[p];
        ans.push_back(min);
    }

    for(int i : ans) cout << i << endl;

    return 0;
}