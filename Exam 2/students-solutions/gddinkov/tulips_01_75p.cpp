#include <bits/stdc++.h>


using namespace std;


int field[1000][1000];
bool visited[1000][1000];
int n, m;

void do_the_thing(std::queue<pair<int, int>> &q, int x, int y, int a, int b){
	if(x < 0 or x >= n or y < 0 or y >= m){
		return;
	}
	if(!visited[x][y] and field[x][y] == field[a][b]){
		q.push({x, y});
	}
}

void BFS(int i, int j, int n, int m){
	std::queue<pair<int, int>> q;
	q.push({i, j});
	while(!q.empty()){
		auto v = q.front();
		q.pop();
		int x = v.first;
		int y = v.second;
		visited[x][y] = 1;
		do_the_thing(q, x - 1, y, x, y);
		do_the_thing(q, x + 1, y, x, y);
		do_the_thing(q, x, y - 1, x, y);
		do_the_thing(q, x, y + 1, x, y);
	}
 	
}

int count_components(int n, int m){
	int res = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(visited[i][j]) continue;
			BFS(i, j, n, m);
			++res;
		}
	}
	return res;
	
	
	
}


int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		
		std::cin >> n >> m;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				std::cin >> field[i][j] ;
			}
		}
		
		
		std::cout << count_components(n, m);
		
		
			
		
}