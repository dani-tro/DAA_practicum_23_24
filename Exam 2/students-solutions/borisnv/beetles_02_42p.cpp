#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int u, v;
	long long w;
	bool operator<(const Edge &other) {return w < other.w;}
};
const int MAXN = 100005;
int		  n;
int		  p[MAXN];
int		  d[MAXN];

int find(int a) {
	if (p[a] == -1) return a;
	return p[a] = find(p[a]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (d[a] > d[b]) p[b] = a;
	else if (d[a] < d[b]) p[a] = b;
	else {
		p[a] = b;
		++d[b];
	}
}

vector<Edge> g;

struct Beet {
	int	 x, y;
	bool operator<(const Beet &other) { return x < other.x; };
};
vector<Beet> b;

int main() {
	cin >> n;
	fill(p, p + n, -1);

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		b.push_back({x, y});
	}

	sort(b.begin(), b.end());

	for (int i = 0; i < (int)b.size(); ++i) {
		for (int j = max(0, i - 5); j < min((int)b.size(), i + 5); ++j) {
			if (i != j) {
				long long dx = (b[i].x - b[j].x);
				long long dy = (b[i].y - b[j].y);

				long long dist = dx * dx + dy * dy;
				g.push_back({i, j, dist});
			}
		}
	}

	sort(g.begin(), g.end());
	int comp = n;
	long long cost = 0;
	for(auto [u, v, w] : g) {
		if(find(u) == find(v)) continue;
		uni(u,v);
		cost += w;
		--comp;
		if(comp == 1) break;
	}
	cout << cost << endl;

	return 0;
}
