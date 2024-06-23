#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long llong;
#define MOD 1000000007

const int MAXN = 10000;
int n, m;
int mx, my;
llong F[2][MAXN + 1];
int k;

llong solve(int num, int maxstep)
{
    int i, j, in;
    int cur = 0, op = 1;

    memset(F, 0, sizeof(F));

    F[0][0] = 1;
    for (i=1;i<=k;i++)
    {
        cur ^= 1;
        op ^= 1;
        for (j=0;j<=num;j++)
        {
            F[cur][j] = 0;
            for (in=j;in>=max(0, j-maxstep);in--)
            {
                F[cur][j] += F[op][in];
                if (F[cur][j] >= MOD)
                    F[cur][j] -= MOD;
            }
        }
    }

    return F[cur][num];
}

int main()
{
    llong ans1, ans2;

    scanf("%d %d %d %d %d", &n, &m, &mx, &my, &k);

    ans1 = solve(n, mx);
    ans2 = solve(m, my);

    printf("%lld\n", (ans1 * ans2) % MOD);

    return 0;
}
