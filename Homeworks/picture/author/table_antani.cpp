#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
const int N = 5e3 + 5;

int n, k;
int tab[N][N];

ll p[N][N];
ll sub(int x, int y, int len)
{
    if(x + len - 1 > n || y + len - 1 > n)
        return k;
    return p[x + len - 1][y + len - 1] - p[x + len - 1][y - 1] - p[x - 1][y + len - 1] + p[x - 1][y - 1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> tab[i][j];
            p[i][j] = tab[i][j] + p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1];
        }

    int side = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            while(sub(i, j, side) < k)
                side++;

    if(side == n + 1)
        cout << -1 << endl;
    else
        cout << side << endl;

    return 0;
}

/*

5 10
1 2 3 4 5
10 0 7 0 4
0 0 2 1 3
5 0 3 0 2
0 5 0 8 0

*/
