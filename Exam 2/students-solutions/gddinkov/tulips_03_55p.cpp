#include <bits/stdc++.h>


using namespace std;


int field[1000][1000];
bool visited[1000][1000];
int n, m;
std::queue<pair<int, int>> q;



void do_the_thing(std::queue<pair<int, int>> &q, int x, int y, int a, int b){
	if(x < 0 or x >= n or y < 0 or y >= m){
		return;
	}
	if(!visited[x][y] and field[x][y] == field[a][b]){
		q.push({x, y});
	}
}

void DFS(int i, int j, int n, int m){
	visited[i][j] = 1;
	if(i > 0 and !visited[i-1][j] and field[i-1][j] == field[i][j]) 
		DFS(i - 1, j, n, m);
	
	if(i < n - 1 and ! visited[i+1][j] and field[i+1][j] == field[i][j]) 
		DFS(i+1, j, n, m);
	
	if(j > 0 and !visited[i][j-1] and field[i][j-1] == field[i][j])
		DFS(i, j-1, n, m);
	
	if(j < n - 1 and ! visited[i][j+1] and field[i][j+1] == field[i][j]) DFS(i, j+1, n, m);
 	
}

int count_components(int n, int m){
	int res = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(visited[i][j]) continue;
			DFS(i, j, n, m);
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