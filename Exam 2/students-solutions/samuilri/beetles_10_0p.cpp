#include <algorithm>
#include <vector>
#include <queue>
# include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100005;
struct edge {
	unsigned long long u, v, w;
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
	for (int i = 0; i < n; i++) {
	unsigned long long x, y;
	std::cin >> x >> y;
	points.push_back({ x , y });
	}

	for (unsigned long long i = 0; i < n; i++) {
		for (unsigned long long j = i + 1; j < n; j++) {
			unsigned long long int ww;
			
				ww = ((points[i].first - points[j].first) * (points[i].first - points[j].first)) +
					((points[i].second - points[j].second) * (points[i].second - points[j].second));
			
			g[i].push_back({ i,j,ww });
			//std::cout <<i<<" " <<j<<" " << ((points[i].first - points[j].first) * (points[i].first - points[j].first)) +
			//	((points[i].second - points[j].second) * (points[i].second - points[j].second))<<endl;
			g[j].push_back({ j,i,ww });
			/*g[i].push_back({ i,j,((points[i].first - points[j].first) * (points[i].first - points[j].first))+
				((points[i].second - points[j].second) * (points[i].second - points[j].second)) });
			cout << ((points[i].first - points[j].first) * (points[i].first - points[j].first)) +
				((points[i].second - points[j].second) * (points[i].second - points[j].second))<<endl;
			g[j].push_back({ j,i,((points[i].first - points[j].first) * (points[i].first - points[j].first)) +
				((points[i].second - points[j].second) * (points[i].second - points[j].second)) });*/
		}
		//std::cout << endl;
	}




	added[1] = 1;
	unsigned long long sum = 0;
	for (auto u : g[0]) {
		pq.push(u);
		
	}
	while (!pq.empty()) {
		edge curr_ed = pq.top();
		
		pq.pop();
		if (added[curr_ed.v]) continue;
		ans.push_back(curr_ed);
		
		sum += curr_ed.w;
		//std::cout << "curr_ed.w:" << curr_ed.w << endl;
		unsigned long long to = curr_ed.v;
		added[to] = 1;
		for (auto u : g[to]) pq.push(u);
	}
	//std::cout << "ans: " << ans.size() << endl;
		std::cout << sum << endl;
}