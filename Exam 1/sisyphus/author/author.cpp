#include<bits/stdc++.h>
#define N 100000
using namespace std;
typedef long long ll;
ll i,j,p,q,n,m,k,a[N+6],dp[N+6][3],s[N+6],ans;
pair <ll,ll> c[10*N+6];
struct Int
{
    ll l,r,st;
}b[N+6];
bool fff(Int a,Int b)
{
    return (a.st>b.st);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
    {
        cin>>p>>q;
        c[i].first=p;c[i].second=q;
        dp[p][0]++;dp[q][1]++;
    }
    p=1;q=0;
    for(i=1;i<=n;i++)
    {
        dp[i][2]=dp[i][0]+dp[i-1][2]-dp[i-1][1];
       // cout<<dp[i][2]<<" ";
        if(dp[i][2]!=dp[i-1][2] && i>1)
        {
            b[++q] = {p,i-1,dp[i-1][2]};
            p=i;
        }
    }
    b[++q] = {p,n,dp[n][2]};
    sort(b+1,b+q+1,fff);
    for(i=1;i<=q;i++)
    {
        //cout<<b[i].l<<" "<<b[i].r<<" "<<b[i].st<<endl;
        for(j=b[i].l;j<=b[i].r;j++)
        {
            if(k>a[j])
            {
                k-=a[j];
                a[j]=0;

            }
            else
            {
                a[j]-=k;
                k=0;
            }
            if(k==0)break;
        }
        if(k==0)break;
    }
    for(i=1;i<=n;i++)
    {
        //cout<<a[i]<<" ";
        s[i]=s[i-1]+a[i];
    }
    ans=0;
    for(i=1;i<=m;i++)
    {
        p=c[i].first;q=c[i].second;
        ans+=s[q]-s[p-1];
    }
    cout<<ans<<endl;
    return 0;
}
/**
4 2 2
1 2 3 4
1 4
3 4

6 6 9
7 2 3 4 5 9
1 2
1 2
3 4
3 4
3 4
5 6
*/
