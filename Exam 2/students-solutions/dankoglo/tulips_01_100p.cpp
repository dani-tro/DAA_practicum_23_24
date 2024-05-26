#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define MAXN 1100
#define MAXM 1100


void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int gr[MAXN][MAXM];

int n, m;

bool visited[MAXN][MAXM];
void dfs(int start_x, int start_y)
{
    if(start_x < 0 || start_x >= n || start_y < 0 || start_y >= m)
        return;

    if(visited[start_x][start_y]) return;
    visited[start_x][start_y] = true;

    if(gr[start_x][start_y] == gr[start_x-1][start_y])
        dfs(start_x - 1, start_y);

    if(gr[start_x][start_y] == gr[start_x+1][start_y])
        dfs(start_x + 1, start_y);

    if(gr[start_x][start_y] == gr[start_x][start_y-1])
        dfs(start_x, start_y - 1);
    
    if(gr[start_x][start_y] == gr[start_x][start_y+1])
        dfs(start_x, start_y + 1);
}

int counter;
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> gr[i][j];
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << gr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                dfs(i, j);
                counter++;
            }
        }
    }
    cout << counter << endl;

    return 0;
}

