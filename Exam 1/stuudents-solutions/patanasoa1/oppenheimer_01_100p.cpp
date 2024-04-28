#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAX = 100'007;
long long N, K;
long long arr[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int maxV = 1;
	priority_queue<long long, vector<long long>, greater<long long> > pq;

	pq.push(arr[0]);
	for (int i = 1; i < N; i++) {
		while (!pq.empty() && arr[i] - pq.top() > K) pq.pop();

		pq.push(arr[i]);

		maxV = max(maxV, (int)pq.size());
	}

	cout << maxV << endl;
}