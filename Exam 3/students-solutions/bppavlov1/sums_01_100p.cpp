#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

unordered_set<int> sums;
queue<int> q;

int n, a, b;
int ar[101];
int dp[101];

int main() {
    cin >> n >> a >> b;

    for(int i = 1; i <= n; i++) cin >> ar[i];
    for(int i = 1; i <= n; i++)
	{
		for(int x : sums)
		{
			q.push(x + ar[i]);
		}
		while(!q.empty())
		{
			sums.insert(q.front());
			q.pop();
		}
		sums.insert(ar[i]);
	}
	
    int counter = 0;
    for(int x : sums) {
        if (x >= a && x <= b && dp[x] == false) {
            dp[x] = true;
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}
