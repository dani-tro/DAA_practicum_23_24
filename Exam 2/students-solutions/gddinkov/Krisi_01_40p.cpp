#include <bits/stdc++.h>


using namespace std;

bool done[10000];
int dists[10000];

void dijkstra(vector<vector<pair<int, int>>> G, int n){
		auto cmp = [](pair<int, int> l, pair<int, int> r){ return l.second > r.second; };
		std::priority_queue<pair<int, int>, std::vector<pair<int,int>>, decltype(cmp)> q{cmp};
		for(int i = 0; i < n; ++i){
			if(dists[i] == 0){
				q.push({i, 0});
				dists[i] = -1;
			}
		}
		while(!q.empty()){
			pair<int, int> x = q.top();
			q.pop();
			int d = x.second;
			int v = x.first;
			
			done[v] = 1;
			if(dists[v] == -1 or dists[v] > d){
				dists[v] = d;
				for(auto e : G[v]){
					if(!done[e.first]) q.push({e.first, d + e.second});
				}
			}
		}
		
}

int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		
		int n; std::cin >> n;
		vector<vector<pair<int, int>>> G{n, vector<pair<int, int>>{}};
		
		int m; std::cin >> m;
		for(int i = 0; i < m; ++i){
			int x, y, t; std::cin >> x >> y >> t;
			G[x].push_back({y, t});
			G[y].push_back({x, t});
		}
		
		
		for(int i = 0; i < n; ++i){
			dists[i] = -1;
		}
		
		int k; std::cin >> k;
		for(int i = 0; i < k; ++i){
			int x; std::cin >> x;
			dists[x] = 0;
		}
		
		dijkstra(G, n);
		
		int q; std::cin >> q;
		for(int i = 0; i < q; ++i){
			int h; std::cin >> h; std::cout << dists[h] << std::endl;
		}
			
		
}