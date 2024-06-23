#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long llong;
#define MOD 1000000007

const int MAXN = 3000;
int n, m;
int limitx, limity;
llong F[MAXN + 1][MAXN + 1];
llong presums[MAXN + 1][MAXN + 1];
int k;

llong solve(llong num, llong maxstep)
{
    int i, j, in;

    memset(F, 0, sizeof(F));
    memset(presums, 0, sizeof(presums));

    for (i=0;i<=num;i++)
    {
        presums[0][i] = 1;
    }

    for (i=1;i<=k;i++)
    {
        for (j=0;j<=num;j++)
        {
            if (j - maxstep > 0)
            {
                F[i][j] = presums[i-1][j] - presums[i-1][j - maxstep - 1];
                if (F[i][j] < 0)
                    F[i][j] += MOD;
            }
            else
            {
                F[i][j] = presums[i-1][j];
            }
        }

        presums[i][0] = F[i][0];
        for (j=1;j<=num;j++)
        {
            presums[i][j] = presums[i][j-1] + F[i][j];
            if (presums[i][j] >= MOD)
                presums[i][j] -= MOD;
        }
    }

    return F[k][num];
}

int main()
{
    llong ans1, ans2;

    scanf("%d %d %d %d %d", &n, &m, &limitx, &limity, &k);

    ans1 = solve(n, limitx);
    ans2 = solve(m, limity);

    printf("%lld\n", (ans1 * ans2) % MOD);

    return 0;
}
