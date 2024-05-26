#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20007;
int k, nodesCount;
vector<int> adj[MAX];
//int temp[MAX];
vector<int> temp;
int d[MAX];

bool toposort() {
	int ctr = 0;
	queue<int> q;

	for (int i = 0; i < MAX; i++) {
		for (int y : adj[i]) {
			d[y]++;
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
		temp.clear();
		temp.reserve(n);
		int a;
		for (int j = 0; j < n; j++) {
			cin >> a;
			if (d[a] == -1) {
				d[a] = 0;
				nodesCount++;
			}
			temp.push_back(a);

			//if (d[temp[j]] == -1) {
			//	d[temp[j]] = 0;
			//	nodesCount++;
			//}

		}
		for (size_t j = 0; j < temp.size() - 1; j++) {
			for (size_t k = j + 1; k < temp.size(); k++) {
				adj[temp[j]].push_back(temp[k]);
			}
		}
	}

	cout << toposort() << endl;
}