#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <climits>
#include <set>

using namespace std;

int MAXF = 20020;
int n;

vector<vector<int>> graph(MAXF);
vector<int> in(MAXF, 0);
set<int> flowers;

void toposort() {
	priority_queue<int> pq;

	for (int i : flowers) {
		if (in[i] == 0) pq.push(i);
	}

	int len = 0;

	while (!pq.empty()) {
		int u = pq.top();
		pq.pop();
		len++;

		for (int v : graph[u]) {
			in[v]--;
			if (in[v] == 0) pq.push(v);
		}
	}

	cout << (len == flowers.size()) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	int prev, curr, m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		cin >> prev;
		flowers.insert(prev);
		for (int i = 1; i < m; i++) {
			cin >> curr;
			flowers.insert(curr);
			graph[prev].push_back(curr);
			in[curr]++;
			prev = curr;
		}
	}

	toposort();
}