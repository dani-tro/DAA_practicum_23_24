#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long llong;
#define MOD 1000000007

const int MAXN = 1000;
int n, m;
int mx, my;
llong F[MAXN + 1][MAXN + 1];
int k;

llong solve(int num, int maxstep)
{
    int i, j, in;

    memset(F, 0, sizeof(F));

    F[0][0] = 1;
    for (i=1;i<=k;i++)
    {
        for (j=0;j<=num;j++)
        {
            for (in=j;in>=max(0, j-maxstep);in--)
            {
                F[i][j] += F[i-1][in];
                if (F[i][j] >= MOD)
                    F[i][j] -= MOD;
            }
        }
    }

    return F[k][num];
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
