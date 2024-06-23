#include<cstdio>
using namespace std;

long long n, p;
long long v[100001], t[100001];
long long c[100001];


int main()
{
    long long pos;
    scanf("%lld %lld",&n, &p);
    for(long long i=1; i<=n; i++)
      { scanf("%lld %lld", &t[i], &v[i]);
        c[i]=t[i]+v[i];
      }
    long long br=0;
    while(br<p)
    {
        pos=1;
        for(long long i=2; i<=n; i++)
          if(c[i]<c[pos]) pos=i;
        br++;
        c[pos]+=t[pos];
        
    }
    printf("%lld\n",c[pos]-t[pos]);
    return 0;
      
    
    return 0;
}