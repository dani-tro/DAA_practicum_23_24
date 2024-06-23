#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

const llong MOD = 1000000007LL;
int n, m, mx, my, k;

llong ans = 0;
void track(int x, int y, int movesLeft)
{
    if (movesLeft == 0)
    {
        if (x == n && y == m)
            ans++;
        return;
    }

    int limX = min(x + mx, n);
    int limY = min(y + my, m);

    for (int i = x; i <= limX; i++)
    {
        for (int j = y; j <= limY; j++)
        {
            track(i, j, movesLeft - 1);
        }
    }
}

int main()
{
    scanf("%d %d %d %d %d", &n, &m, &mx, &my, &k);

    track(0, 0, k);

    printf("%lld\n", ans % MOD);

    return 0;
}
