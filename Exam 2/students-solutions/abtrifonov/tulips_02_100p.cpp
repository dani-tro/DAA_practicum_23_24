#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;


int matrix[1000][1000];

int n, m, x, result, i, j;

bool common(int a)
{
    if (i == 0 && j == 0)
    {
        return false;
    }
    else if (i == 0 && matrix[i][j - 1] != a)
    {
        return false;
    }
    else if (j == 0 && matrix[i - 1][j] != a)
    {
        return false;
    }
    else if (matrix[i - 1][j] != a && matrix[i][j - 1] != a)
    {
        return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> x;
            matrix[i][j] = x;
            if (!common(x))
            {
                result++;
            }
        }
    }

    cout << result << endl;
    return 0;
}
