#include <cstdio>
#include <algorithm>
using namespace std;

struct mmm {
   int a;
   long long t;
};

mmm a[100001];

long long N,P;
long long ll,pp,ss;

bool Stawa(long long Wr){
long long  i,sum;
bool Fl=false;
    sum=0;
    for (i=1;i<=N;i++)
     if (Wr>a[i].t) {
       sum=sum+((Wr-a[i].t)/a[i].a);
       if (sum>=P)  {
         Fl=true;
         break;
       }
     }
    return Fl;
}

int main () {
long long i;
  scanf("%lld %lld",&N,&P);
  for (i=1;i<=N;i++) {
    scanf("%d %lld",&a[i].a,&a[i].t);
  }  

bool Fl;
    ll=0;
    pp=10000000000000000LL;
    while (abs(pp-ll)>1) {
      ss=(ll+pp)/2; 
      if (Stawa(ss))
       pp=ss;
       else
       ll=ss;
    }
  printf("%lld\n",pp);
  return 0;
}
/*
3 7
7 10
8 7
12 6

=========
2 10
1 7
10 1



*/
