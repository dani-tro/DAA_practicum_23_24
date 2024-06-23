#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long llong;
#define MOD 1000000007

int n, m;
int limitx, limity;
llong F[10111];
llong presums[10111];
int k;

llong solve(llong num, llong maxstep)
{
    int i, j, in;

    memset(F, 0, sizeof(F));
    memset(presums, 0, sizeof(presums));

    for (i=0;i<=num;i++)
    {
        presums[i] = 1;
    }

    for (i=1;i<=k;i++)
    {
        for (j=0;j<=maxstep;j++)
        {
            F[j] = presums[j];
        }

        for (j=maxstep+1;j<=num;j++)
        {
            F[j] = presums[j] - presums[j - maxstep - 1];
            if (F[j] < 0)
                F[j] += MOD;
        }

        presums[0] = F[0];
        for (j=1;j<=num;j++)
        {
            presums[j] = presums[j-1] + F[j];
            if (presums[j] >= MOD)
                presums[j] -= MOD;
        }
    }

    return F[num];
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
