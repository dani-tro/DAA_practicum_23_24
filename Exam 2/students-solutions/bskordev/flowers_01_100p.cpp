#include <iostream>
#include <vector>
#include <queue>


struct Graph {
	std::vector<int> adj[20001];

	int size = 0;

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}
};

Graph g;
int in[20001];
int count[20001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);


	for (int i = 1; i <= 20000; i++) {
		in[i] = 0;
		count[i] = 0;
	}

	int k;
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		int n;
		std::cin >> n;

		int prev = -1, curr;
		for (int j = 0; j < n; j++) {
			std::cin >> curr;
			if (count[curr] == 0) {
				g.size++;
			}
			count[curr]++;
			if (prev != -1) {
				g.addEdge(prev, curr);
				in[curr]++;
			}
			prev = curr;
		}
	}

	std::queue<int> q;
	for (int i = 1; i <= 20000; i++) {
		if (in[i] == 0 && count[i] > 0) {
			q.push(i);
		}
	}

	std::vector<int> t;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		t.push_back(x);
		for (int& y : g.adj[x]) {
			in[y]--;
			if (in[y] == 0) {
				q.push(y);
			}
		}
	}

	if (t.size() == g.size) {
		std::cout << 1;
	}
	else {
		std::cout << 0;
	}
	std::cout << std::endl;

	return 0;
}