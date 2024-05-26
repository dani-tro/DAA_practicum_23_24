#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
#include<algorithm>


short n, m, node, i, j;
short table[1000][1000];
bool visited[1000][1000];
long long components = 0;
std::queue<std::pair<short, short>> q;
void bfs(short row, short col){
    q.push({row, col});
    while(!q.empty()){
        row = q.front().first;
        col = q.front().second;
        q.pop();
        visited[row][col] = true;
        if(row - 1 >= 0 && !visited[row - 1][col] && table[row][col] == table[row - 1][col]){
            q.push({row - 1, col});
        }
        if(col - 1 >= 0 && !visited[row][col - 1] && table[row][col] == table[row][col - 1]){
            q.push({row, col - 1});
        }
        if(row + 1 < n && !visited[row + 1][col] && table[row][col] == table[row + 1][col]){
            q.push({row + 1, col});
        }
        if(col + 1 < m && !visited[row][col + 1] && table[row][col] == table[row][col + 1]){
            q.push({row, col + 1});
        }
    }
}
int main(){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            visited[i][j] = false;
            std::cin >> table[i][j];
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(!visited[i][j]){
                components++;
                bfs(i, j);
            }
        }
    }
    std::cout << components;
    return 0;
}