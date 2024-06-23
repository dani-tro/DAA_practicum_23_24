#include<iostream>
using namespace std;

const int MAXN = 701;
int a[MAXN], f[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
      cin >> a[i];
    for(int l=3; l<=n; l++)
    {
        for(int i=0; i<=n-l; i++)
        {
            int j=i+l-1;
            f[i][j]=0;
            for(int k=i+1; k<=j-1; k++)
            {
                int v=f[i][k]+f[k][j]+a[k]*(a[i]+a[j]);
                if(f[i][j]<v) f[i][j]=v;
            }
        }
    }
    cout << f[0][n-1] << '\n';
    return 0;
}