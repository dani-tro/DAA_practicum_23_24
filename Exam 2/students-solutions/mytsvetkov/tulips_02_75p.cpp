#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int n, m;
int garden[MAXN][MAXN];
bool visited[MAXN][MAXN];

void dfs(int i, int j) {
    visited[i][j] = true;

    if(i + 1 < n && garden[i + 1][j] == garden[i][j]) {
        visited[i + 1][j] = true;
        dfs(i + 1, j);
    }
    if(j + 1 < m && garden[i][j + 1] == garden[i][j]) {
        visited[i][j + 1] = true;
        dfs(i, j + 1);
    }
}

int main(){

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> garden[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}