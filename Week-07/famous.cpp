#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

int n, k, f, m, cnt, p, q, br[MAX], node;

map<string, int> mp;

set<pair<int, int> > edges;

string a, b, names[MAX];

vector<int> gr[MAX];

bool famous[MAX];

vector<string> ans;

queue<int> qu;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k >> f >> m;
	for(int i = 0; i < f; i++)
	{
		cin >> a;
		if(!mp.count(a))
		{
			names[cnt] = a;
			mp[a] = cnt++;
		}
		p = mp[a];
		
		qu.push(p);
		famous[p] = 1;
	}
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if(!mp.count(a))
		{
			names[cnt] = a;
			mp[a] = cnt++;
		}
		if(!mp.count(b))
		{
			names[cnt] = b;
			mp[b] = cnt++;
		}
		p = mp[a];
		q = mp[b];
		
		if(p > q)swap(p, q);
		if(!edges.count({p, q}))
		{
			gr[p].push_back(q);
			gr[q].push_back(p);
			edges.insert({p, q});
		}
	}
	
	while(!qu.empty())
	{
		node = qu.front();
		qu.pop();
		for(int v : gr[node])
		{
			br[v]++;
			if(br[v] == k && !famous[v])
			{
				qu.push(v);
				famous[v] = 1;
			}
		}
	}
	
	for(int i = 0; i < cnt; i++)
	{
		if(famous[i] == 1)
		{
			ans.push_back(names[i]);
		}
	}
	
	sort(ans.begin(), ans.end());
	
	for(string name : ans)cout << name << " ";
	cout << endl;
	
	return 0;
}

/*

9 2 3 6
Stancho Elly Rumen
Kriss Pesho
Elly Ani
Elly Kriss
Kriss Stancho
Elly Pesho
Stancho Pancho

*/
