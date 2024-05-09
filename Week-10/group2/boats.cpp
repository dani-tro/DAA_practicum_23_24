#include<bits/stdc++.h>
using namespace std;

template<class T> using matrix = vector<vector<T>>;

matrix<pair<int, int>> G;
matrix<int> maxminedges;

struct unionfind{
	vector<int> par, sz;
	unionfind() {}
	unionfind(int n){
		par.resize(n + 1);
		sz.resize(n + 1);
		for(int i = 1; i <= n; i ++){
			par[i] = i;
			sz[i] = 1;
		}
	}
	int get_par(int x){
		if(par[x] == x) return x;
		else return par[x] = get_par(par[x]);
	}
	void join(int u, int v){
		u = get_par(u);
		v = get_par(v);
		if(u == v) return;
		if(sz[u] < sz[v]) swap(u, v);
		par[v] = u;
		sz[u] += sz[v];
	}
};

void dfs(int u, int p, int min_edge, vector<int> &vec){
	vec[u] = min_edge;
	for(auto [v, w] : G[u]){
		if(v == p) continue;
		dfs(v, u, min(min_edge, w), vec);
	}
}

int main(){
	int n, m, q; cin >> n >> m >> q;
	vector<array<int, 3>> edges(m);
	for(auto &[w, u, v] : edges){
		cin >> u >> v >> w;
	}
	sort(edges.begin(), edges.end(), greater<array<int, 3>>());
	unionfind dsu(n);
	G.resize(n + 1);
	for(auto [w, u, v] : edges){
		if(dsu.get_par(u) == dsu.get_par(v)) continue;
		dsu.join(u, v);
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	maxminedges = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	for(int u = 1; u <= n; u ++){
		dfs(u, u, 1e9, maxminedges[u]);
	}
	for(int i = 1; i <= q; i ++){
		int u, v; cin >> u >> v;
		cout << maxminedges[u][v] << endl;
	}
}
