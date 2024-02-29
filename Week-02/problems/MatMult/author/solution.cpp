#include <cstdio>
int m,n,k;
long long a[20][20], b[20][20], c[20][20];
int main() {
	int i,j,o;
	scanf("%d %d %d", &m, &n, &k);
	for(i=0; i<m; i++)
     for(j=0; j<n; j++)
      scanf("%lld", &a[i][j]);

	for(i=0; i<n; i++)
     for(j=0; j<k; j++)
      scanf("%lld", &b[i][j]);

	for(i=0; i<m; i++)
	 for(j=0; j<k; j++)
	 {
        c[i][j] = 0;
        for(o=0; o<n; o++)
            c[i][j] += a[i][o] * b[o][j];
	 }

	for(i=0; i<m; i++)
	{
        for(j=0; j<k; j++)
         printf(j==0 ? "%lld" : " %lld", c[i][j]);
        printf("\n");
	}
	return 0;
}
