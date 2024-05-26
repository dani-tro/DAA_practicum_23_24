#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 20005

long long n, k, a, b, maxFlower;
vector<long long> g[MAX];
long long in[MAX];


int main()
{
	cin >> k;
	for (size_t i = 0; i < k; i++)
	{
		cin >> n;
		a = b = 0;
		for (size_t j = 0; j < n; j++)
		{
			cin >> b;
			if (maxFlower < b)
				maxFlower = b;

			if (a)
			{
				g[a].push_back(b);
				in[b]++;
			}
			a = b;
		}
	}

	priority_queue<long long> pq;
	for (long long i = 1; i <= maxFlower; i++)
		if (in[i] == 0)
			pq.push(-i);

	long long ans = 0;

	while (!pq.empty())
	{
		a = -pq.top();
		pq.pop();
		ans++;

		for (auto v : g[a])
		{
			in[v]--;
			if (in[v] == 0)
				pq.push(-v);
		}
	}

	if (ans < maxFlower)
	{
		cout << 0;
	}
	else cout << 1;
}