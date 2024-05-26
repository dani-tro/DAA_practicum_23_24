#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long calc(long long x1, long long y1, long long x2, long long y2) {
	return -((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct edge {
	int u;
	int v;
	long long w;
};

bool operator< (const edge& first, const edge& second) {
	return first.w < second.w;
}


const int MAX_SIZE = 100001;
priority_queue<edge> edges;
vector<int> g[MAX_SIZE];

pair<long, long> pairs[MAX_SIZE + 1];

int pr[MAX_SIZE];

bool visited[MAX_SIZE];

bool dali = false;

void dfs(int i) {
	if (visited[i]) {
		dali = true;
	}
	else {
		visited[i] = true;
		for (int v : g[i]) {
			dfs(v);
		}
	}
}

bool has_cycle(int u) {
	dfs(u);
	return dali;
}


int main()
{
	int n;
	cin >> n;
	long x, y;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		pairs[i].first = x;
		pairs[i].second = y;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			edges.push({ i, j, calc(pairs[i].first, pairs[i].second, pairs[j].first, pairs[j].second) });
		}
	}

	fill(pr, pr + MAX_SIZE, -1);

	long long sum = 0;
	int cnt = 0;
	edge ed;
	while (cnt != n - 1) {
		dali = false;
		ed = edges.top();
		g[ed.u].push_back(ed.v);
		fill(visited, visited + MAX_SIZE, false);
		edges.pop();
		if (has_cycle(ed.u)) {
			g[ed.u].pop_back();
		}
		else {
			sum +=(long long) ed.w;
			cnt++;
		}
	}
	cout << -sum;
}