#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 100005

long long n, k, a[MAXN], m, c, x, y;

struct pos {
	long long x;
	int t;

	bool operator<(const pos& other) const {
		if (x == other.x) return t > other.t;
		else return x < other.x;
	}
};
vector<pos> p;

struct part {
	long long val, passCnt;

	bool operator<(const part& other) const {
		if (passCnt == other.passCnt) return val < other.val;
		else return passCnt < other.passCnt;
	}
};

priority_queue<part> pq;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		p.push_back({ x, 1 });
		p.push_back({ y, -1 });
	}
	sort(p.begin(), p.end());

	int cnt = 0;
	int j = 0;
	for (int i = 1; i <= n; i++)
	{
		int endingAtI = 0;
		while (j < p.size() && p[j].x <= i) {
			if (p[j].x == i && p[j].t == -1)
				endingAtI++;
			cnt += p[j].t;
			j++;
		}
		pq.push({ a[i], cnt + endingAtI });
	}

	long long sum = 0;
	long c = 0;

	while (!pq.empty() && pq.top().passCnt > 0) {
		while (c < k && pq.top().val > 0) {
			part temp = pq.top();
			pq.pop();
			pq.push({temp.val - 1, temp.passCnt});
			c++;
		}
		sum += pq.top().val * pq.top().passCnt;
		pq.pop();
	}

	cout << sum << endl;
	return 0;
}