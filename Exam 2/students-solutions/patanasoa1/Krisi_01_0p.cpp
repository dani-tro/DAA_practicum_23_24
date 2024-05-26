#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int MAX = 300'007;
int n, m;

vector<pair<int, int> > adj[MAX]; // (w, v)
int d[MAX];
bool visited[MAX];

void dijkstra(int s) {
	fill(d, d + MAX, INT_MAX);
	fill(visited, visited + MAX, false);
	d[s] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push({ d[s], s });
	while (!pq.empty()) {
		int p = pq.top().second;
		pq.pop();
		if (visited[p]) continue;
		visited[p] = true;

		for (auto& y : adj[p]) {
			if (d[y.second] > d[p] + y.first) {
				d[y.second] = d[p] + y.first;
				pq.push({ -d[y.second], y.second });
			}
		}
	}

	//for (int i = 0; i < n; i++) cout << d[i] << " ";
	//cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	int a, b, t;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		adj[a].push_back({ t, b });
		adj[b].push_back({ t, a });
	}

	int k;
	cin >> k;
	vector<int> ip(k);
	for (int i = 0; i < k; i++) {
		cin >> ip[i];
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a;
		dijkstra(a);

		int minT = INT_MAX;
		for (int x : ip) {
			minT = min(minT, d[x]);
		}
		cout << minT << endl;
	}
}