#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long llong;
#define MOD 1000000007

const int MAXN = 100;
int n, m;
int mx, my;
llong F[MAXN+1][MAXN+1][MAXN+1];
int k;

llong solve()
{
    int i, j, in, ja, i1;

    memset(F, 0, sizeof(F));

    int iter = 0;
    F[0][0][0] = 1;
    for (i=1;i<=k;i++)
    {
        for (j=0;j<=n;j++)
        {
            for (in=0;in<=m;in++)
            {
                int jalim = max(0, j - mx);
                        iter++;
                for (ja=j;ja>=jalim;ja--)
                {
                    int inlim = max(0, in - my);
                    for (i1=in;i1>=inlim;i1--)
                    {
                        F[i][j][in] += F[i-1][ja][i1];
                        if (F[i][j][in] >= MOD)
                            F[i][j][in] -= MOD;

                    }
                }
            }
        }
    }

    return F[k][n][m];
}

int main()
{
    llong ans1, ans2;

    scanf("%d %d %d %d %d", &n, &m, &mx, &my, &k);

    printf("%lld\n", solve());

    return 0;
}
