

#include <iostream>
//#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100000



priority_queue<pair<int, int> > pq;

int n, m, a, b, c, start,k , q;

vector<pair<int, int> > gr[MAX];

bool used[MAX];

int d[MAX];
int dFinal[MAX];

vector<int> K;
vector<int> Q;

void dijkstra(int from)
{
	for(int i = 0; i < n; i++)d[i] = INT_MAX / 2;
	for (int i = 0; i < n; i++)used[i] = false;
	d[from] = 0;
	pq.push({ d[from], from });
	int node, u, w;

	while (!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		if (used[node])continue;
		used[node] = true;

		for (auto p : gr[node])
		{
			u = p.first;
			w = p.second;
			if (d[u] > d[node] + w)
			{
				d[u] = d[node] + w;
				pq.push({ -d[u], u });
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		gr[a].push_back({ b, c });
		gr[b].push_back({ a, c });
	}

	cin >> k;
	
	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		K.push_back(temp);
	}
	for (int i = 0; i < n; i++)dFinal[i] = INT_MAX / 2;

	for (auto s : K) {
		dijkstra(s);
		for (int ii = 0; ii < n; ii++) {
			
			if (d[ii] < dFinal[ii]) {
				dFinal[ii] = d[ii];
			}
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int temp;
		cin >> temp;
		Q.push_back(temp);
	}


	for (int i = 0; i < q; i++) {
		cout << dFinal[Q[i]];
		cout << endl;
	}

	return 0;
}
