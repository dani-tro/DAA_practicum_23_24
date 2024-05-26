#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool used[1000000];
int matrix[1000000];
int n, m;
int curr;

int id(int x, int y)
{
    return x* m + y;
}
int main()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[id(i,j)];
            if (j > 0 && matrix[id(i, j - 1)] == matrix[id(i, j)])
            {
                continue;
            }
            else if (i > 0 && matrix[id(i - 1, j)] == matrix[id(i, j)])
            {
                continue;
            }
            else
            {
                ans++;
            }
        }

    }

    cout << ans;

    
}