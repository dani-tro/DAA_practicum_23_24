#include <stdio.h>

#define MAXD 10000000000000.0
#define BASV 70
#define MAXN 501

int a,b,c,e,ant, s,f;

int ed[MAXN][MAXN], v[MAXN][MAXN], w[MAXN][MAXN], ae[MAXN];

double d[MAXN*MAXN], nt, min;

int ko[MAXN*MAXN], par[MAXN*MAXN];
int tagen[MAXN*MAXN];
int now, next, bra;
int cn, cv, cpos, nn, nv, npos;
int vis[MAXN];

int main() {
   scanf("%d %d %d", &ant, &b, &f);
   s = 0;
   for(a=0;a<ant;a++) ae[a] = 0;
   for(a=0;a<b;a++) {
   	  scanf("%d %d", &c, &e);
      ed[c][ae[c]] = e;
      scanf("%d %d", &v[c][ae[c]], &w[c][ae[c]]);
      ae[c]++;
   }
   for(a=0;a<ant*MAXN;a++) {
       d[a] = MAXD;
       tagen[a] = 0;
   }

   ko[0] = BASV * ant + s;  //start nod
   d[ko[0]] = 0.0;
   par[ko[0]] = -1;

   now = 0;
   next = 1;
   while(now < next) {
   	  min = MAXD;
      for(a=now;a<next;a++) 
		  if(d[ko[a]] < min) {
      	    min = d[ko[a]];
            bra = a;
          }
      cpos = ko[bra];
      cn = cpos % ant;
      cv = cpos / ant;
      ko[bra] = ko[now++];
      tagen[cpos] = 2;
      if(cn == f) { break; }
      for(a=0;a<ae[cn];a++) {
         nn = ed[cn][a];
         nv = v[cn][a]==0?cv:v[cn][a];
         npos = nv * ant + nn;
         if(tagen[npos] < 2) {
         	nt = d[cpos] + (double)w[cn][a] / (double)nv;
            if(nt < d[npos]) {
               d[npos] = nt;
               par[npos] = cpos;
               if(!tagen[npos]) {
                  ko[next++] = npos;
   	              tagen[npos] = 1;
               }
            }
         }
      }
   }
    if(cn!=f) printf("Impossible to reach destination.\n");
    b = 0;
    for(a=cpos;a>=0;a=par[a]) vis[b++] = a % ant;
    for(b--;b>=0;b--) printf("%d ", vis[b]);
    printf("\n");
    return 0;
}
/* 

5 7 1
0 1 30 2
0 2 0 70
2 3 500 1
3 1 1 300
0 4 0 70
4 5 150 1
5 1 0 150

 */
