#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int k, n;
const int MAXN = 20005;
int in[MAXN];
vector<int> g[MAXN];
bool used[MAXN];

bool topo() {
	std::queue<int> q;
	int target = 0;
	for(int i = 0; i < n; ++i) {
		if(used[i] && in[i] == 0) q.push(i);
		if(used[i]) ++target;
	}
	int cnt = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		++cnt;
		for(int v : g[u]) {
			--in[v];
			if(in[v] == 0) q.push(v);
		}
	}
	return cnt == target;
}

int main() {
	cin >> k;
	for(int i = 0; i < k; ++i) {
		int l;
		cin >> l;
		int pr;
		for(int i = 0; i < l; ++i) {
			int c;
			cin >> c;
			--c;
			n = max(n, c);
			used[c] = 1;
			if(i) {
				g[pr].push_back(c);
				++in[c];
			}
			pr = c;
		}
	}
	++n;

	cout << topo();
	return 0;
}
