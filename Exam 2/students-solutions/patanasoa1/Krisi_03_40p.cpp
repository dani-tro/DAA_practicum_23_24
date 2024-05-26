#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 300'007;
int n, m, k, ctr;

vector<pair<int, int> > adj[MAX]; // (w, v)
int d[MAX];
bool visited[MAX];
bool importantNodes[MAX];

void dijkstra(int s) {
	fill(d, d + MAX, INT_MAX);
	fill(visited, visited + MAX, false);
	ctr = 0;
	d[s] = 0;

	int minT = INT_MAX;

	priority_queue<pair<int, int> > pq;
	pq.push({ d[s], s });
	while (!pq.empty()) {
		int p = pq.top().second;
		pq.pop();
		if (visited[p]) continue;
		visited[p] = true;
		if (importantNodes[p]) {
			ctr++;
			minT = min(minT, d[p]);
		}
		if (ctr == k) break;

		for (auto& y : adj[p]) {
			if (d[y.second] > d[p] + y.first) {
				d[y.second] = d[p] + y.first;
				pq.push({ -d[y.second], y.second });
			}
		}
	}

	cout << minT << endl;

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

	cin >> k;
	vector<int> ip(k);
	for (int i = 0; i < k; i++) {
		cin >> ip[i];
		importantNodes[ip[i]] = true;
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a;
		dijkstra(a);
	}
}