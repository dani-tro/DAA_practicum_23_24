#include <bits/stdc++.h>


using namespace std;


bool visited[20001];
bool done[20001];
bool ancestors[20001];


bool DFS(vector<vector<int>> &G, int curr, int n){
	visited[curr] = 1;
	ancestors[curr] = 1;
	
	for(int i = 0; i < G[curr].size(); ++i){
		int v = G[curr][i];
		if(ancestors[v]){
			ancestors[curr] = 0;
			done[curr] = 1;
			return true;
		}
		if(!visited[v] and DFS(G, v, n)){
				ancestors[curr] = 0;
				done[curr] = 1;
				return true;
		}
	}
	
	ancestors[curr] = 0;
	done[curr] = 1;
	return false;
}



bool isAcyclic(vector<vector<int>> &G, int n){
	for(int i = 0; i < n; ++i){
		if((!done[i])  and DFS(G, i, n)){
			return false;
		}
	}
	
	return true;
	
}


int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		
		vector<vector<int>> G{20001, vector<int>{}};
		
		
		int k; std::cin >> k;
		
		for(int i = 0; i < k; ++i){
			int cnt; std::cin >> cnt;
			if(cnt == 0) continue;
			int prev; std::cin >> prev;
			for(int j = 1; j < cnt; ++j){
				int curr; std::cin >> curr;
				G[curr].push_back(prev);
				prev = curr;
			}
		}
		
		
		
		std::cout << isAcyclic(G, 20001);
		
		
			
		
}