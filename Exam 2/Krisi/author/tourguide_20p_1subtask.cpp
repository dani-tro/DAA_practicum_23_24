#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct path {
    int to;
    int wht;
};
bool operator< (path ex1, path ex2) {
     if (ex1.wht>ex2.wht) return true;
     return false;
}
vector <int> a[100001],wht[100001];
priority_queue <path> min1;
int used[100001],ans[100001];
int main () {
    int n,m,k,i,x,y,t,q;
    path curr,ex;
    scanf("%d%d",&n,&m);
    for (i=0; i<m; i++) {
        scanf("%d%d%d",&x,&y,&t);
        a[x].push_back(y); wht[x].push_back(t);
        a[y].push_back(x); wht[y].push_back(t);
        }
    scanf("%d",&k);
    scanf("%d",&x);
    ex.to=x;
    ex.wht=0;
    min1.push(ex);
    for (;;) {
        curr.to=-1;
        for (;;) {
            if (min1.empty()==1) break;
            ex=min1.top();
            min1.pop();
            if (used[ex.to]==0) {
               curr=ex;
               break;
               }
            }
        if (curr.to==-1) break;
        ans[curr.to]=curr.wht;
        used[curr.to]=1;
        for (i=0; i<a[curr.to].size(); i++) {
            if (used[a[curr.to][i]]==0) {
               ex.to=a[curr.to][i]; ex.wht=curr.wht+wht[curr.to][i];
               min1.push(ex);
               }
            }
        }
    scanf("%d",&q);
    for (i=0; i<q; i++) {
        scanf("%d",&x);
        printf("%d\n",ans[x]);
        }
    return 0;
}
