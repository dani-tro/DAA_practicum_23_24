#include <bits/stdc++.h>

using namespace std;

#define MAXN 110000

#define MAXM 210000

long long n, m, d[MAXN], par[MAXN], ans, cnt;

struct edge
{
	long long a, b, c;
	
	bool operator<(const edge& other)
	{
		return c < other.c;
	}
} e[MAXM];

int find(int a)
{
	if(par[a] == 0)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	
	cnt--;
	if(d[a] > d[b])
	{
		par[b] = a; 
	}
	else
	{
		par[a] = b;
		if(d[a] == d[b])d[b]++;
	}
	return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    cnt = n;
    
    for(int i = 0; i < m; i++)cin >> e[i].a >> e[i].b >> e[i].c;
    sort(e, e + m);
    
    for(int i = 0; i < m; i++)
    {
    	if(find(e[i].a) != find(e[i].b))
    	{
    		uni(e[i].a, e[i].b);
    		ans += e[i].c;
    		// cout << e[i].a << " " << e[i].b << " " << e[i].c <<endl;
 		}
	}
    
    if(cnt == 1)cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}

/*



*/
