#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 20001;
vector<int> gr[MAXN];
int par[MAXN];
bool used[MAXN];
bool tracker[MAXN];
queue<int> q;
int n, flowers;
vector<int> curr_flowers;
bool is_cycle = false;
bool cycle(int from)
{
	/*
	cout << from << endl;
	for (auto fl : curr_flowers)
	{
		if (tracker[fl])
		{
			cout << 1 << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}
	cout << endl;
	*/
	tracker[from] = true;
	for (int adj : gr[from])
	{
		if (tracker[adj])
		{
			return is_cycle = true;
		}
		cycle(adj);
		tracker[adj] = false;
	}

	return false;
}
bool has_cycle(int from)
{
	for (auto fl: curr_flowers)
	{
		tracker[fl] = false;
	}
	q.push(from);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		if (tracker[node])
		{
			return true;
		}
		used[node] = true;
		tracker[node] = true;
		for (int adj : gr[node])
		{
			q.push(adj);
		}
	}

	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(par, par + MAXN, -1);
	cin >> n;
	int prev, curr, adj;
	for (int i = 0; i < n; i++)
	{
		cin >> flowers;
		for (int j = 0; j < flowers; j++)
		{
			if (j == 0)
			{
				cin >> prev;
				if(!used[prev]) curr_flowers.push_back(prev);
			}
			else
			{
				cin >> curr;

				if(!used[curr]) curr_flowers.push_back(curr);

				gr[prev].push_back(curr);
				par[curr] = prev;
				if (i == 0)
				{
					used[prev] = true;
					used[curr] = true;
				}
					
				
				prev = curr;
			}
		}
		if (i != 0)
		{
			for (int fl : curr_flowers)
			{
				cycle(fl);
				if (is_cycle)
				{
					cout << 0 << endl;
					exit(9);
				}
				is_cycle = false;
				for (auto fl : curr_flowers)
				{
					tracker[fl] = false;
				}
			}
			
		}
	}

	cout << 1 << endl;
}