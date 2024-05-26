#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20007;
int k, nodesCount;
vector<int> adj[MAX];
int temp[MAX];
int d[MAX];
bool nodes[MAX];

bool toposort() {
	int ctr = 0;
	queue<int> q;

	for (int i = 0; i < MAX; i++) {
		for (int y : adj[i]) {
			d[y] = d[y] == -1 ? 1 : d[y] + 1;
		}
	}

	for (int i = 0; i < MAX; i++) {
		if (d[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int p = q.front();
		q.pop();
		ctr++;
		for (int y : adj[p]) {
			d[y]--;
			if (d[y] == 0) q.push(y);
		}
	}

	return ctr == nodesCount;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	fill(d, d + MAX, -1);

	cin >> k;
	int n;
	for (int i = 0; i < k; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> temp[j];
			if (!nodes[temp[j]]) {
				nodes[temp[j]] = true;
				nodesCount++;
			}
		}
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				adj[temp[j]].push_back(temp[k]);
				d[temp[j]] = 0;
			}
		}
	}

	cout << toposort() << endl;
}