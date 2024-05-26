#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

const size_t MAX_VALUE = 1000;

int grid[MAX_VALUE][MAX_VALUE];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    grid[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int maxBeetles = n * m;
    int currentCheck, lastCheck;
    bool alreadyChecked = false;

    for (int i = 0; i < n; i++)
    {
        lastCheck = -1;
        for (int j = 0; j < m; j++)
        {

            currentCheck = grid[i][j];

            if (lastCheck != currentCheck) alreadyChecked = false;

            if (i != 0 && alreadyChecked == false) {
                if (grid[i][j] == grid[i - 1][j]) maxBeetles--;
                alreadyChecked = true;
            }

            if (grid[i][j + 1] == grid[i][j]) maxBeetles--;
            lastCheck = currentCheck;
        }
    }

    cout << maxBeetles;

    return 0;
}