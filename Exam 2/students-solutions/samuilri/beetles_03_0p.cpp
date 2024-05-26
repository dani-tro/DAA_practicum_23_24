
#include <algorithm>
#include <vector>
#include <queue>
# include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100005;
struct edge {
	long long u, v, w;
	bool operator <(const edge& other)const {
		return w > other.w;
	}
};
vector <edge> g[MAXN];

vector<pair<int, int>> points;




bool added[MAXN];
priority_queue <edge> pq;
vector <edge> ans;
int main() {
	ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	long long n;
	std::cin >> n;
	for (long long i = 0; i < n; i++) {
	long long x, y;
	std::cin >> x >> y;
	points.push_back({ x , y });
	}

	for (long long i = 0; i < n; i++) {
		for (long long j = i + 1; j < n; j++) {
			g[i].push_back({ i,j,(points[i].first - points[j].first) * (points[i].first - points[j].first)+
				(points[i].second - points[j].second) * (points[i].second - points[j].second) });
			g[j].push_back({ j,i,(points[i].first - points[j].first) * (points[i].first - points[j].first) +
				(points[i].second - points[j].second) * (points[i].second - points[j].second) });
		}
	}




	added[0] = 1;
	long long sum = 0;
	for (auto u : g[0]) {
		pq.push(u);
		
	}
	while (!pq.empty()) {
		edge curr_ed = pq.top();
		
		pq.pop();
		if (added[curr_ed.v]) continue;
		ans.push_back(curr_ed);
		
		sum += curr_ed.w;
		long long to = curr_ed.v;
		added[to] = 1;
		for (auto u : g[to]) pq.push(u);
	}
		cout << sum << endl;
}
