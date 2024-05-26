#include <iostream>
#include <vector>

using namespace std;

bool visited[20001];
vector<vector<long>> graph(20001);

bool dfs(long a, vector<bool>& curr) {		
	if (curr[a]) {
		return false;
	}
	curr[a] = true;
	if (visited[a] == true)
	{
		curr[a] = false;
		return true;
	}
	visited[a] = true;
	for (auto to : graph[a])
	{
		if (!dfs(to, curr))
		{
			curr[a] = false;
			return false;
		}
	}
	curr[a] = false;
	return true;
}

bool detect_cycle() {
	for (long i = 1; i <= 20000; i++)
	{
		vector<bool> curr(20001);
		if (!dfs(i, curr)) {
			return false;
		}
	}
	return true;
}

int main()
{
    long n;  cin >> n;
	for (long i = 0; i < n; i++)
	{
		long m; cin >> m;
		long prev; cin >> prev;
		for (long j = 0; j < m-1; j++)
		{
			long curr; cin >> curr;
			graph[curr].push_back(prev);
			prev = curr;
		}
	}
	cout << detect_cycle() << endl;
}