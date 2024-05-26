#include <bits/stdc++.h>
using namespace std;

#define MAX 1024

int n, m, ans;
vector<int> tulip[MAX];

int main()
{
    cin >> n >> m;

    ans = n * m;

    int i, j, t;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            cin >> t;
            tulip[i].push_back(t);
            if (i != 0 && tulip[i - 1][j] == t)
            {
                ans--;
            }
            else if (j != 0 && tulip[i][j - 1] == t)
            {
                ans--;
            }
        }
    }

    cout << ans;
}