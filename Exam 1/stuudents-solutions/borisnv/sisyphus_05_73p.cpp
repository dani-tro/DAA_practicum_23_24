#include <algorithm>
#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

struct event {
	int	 x;
	bool is_end;
};
struct interval {
	int		coef;
	int64_t capacity;
};

bool cmp1(const event &x, const event &y) { return x.x < y.x || (x.x == y.x && x.is_end < y.is_end); }
bool cmp2(const interval &x, const interval &y) { return x.coef > y.coef; }

int n, m;
int64_t k;

int			 a[100001];
int64_t			 pr[100002];
vector<event>	 events;
vector<interval> intervals;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pr[i + 1] = pr[i] + a[i];
	}

	events.reserve(2 * m);
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		events.push_back({l, 0});
		events.push_back({r, 1});
	}
	sort(events.begin(), events.end(), cmp1);

	// for (int i = 0; i < n + 1; ++i) {
	//	cout << pr[i] << " ";
	// }
	// cout << endl;

	int cnt = 0;
	int64_t sum = 0;
	for (int i = 0; i < 2 * m; ++i) {
		if (i) {
			int begin = events[i - 1].x + events[i - 1].is_end;
			int end	  = events[i].x - 1 + events[i].is_end;
			//cout << "interval from " << begin << " to " << end << endl;
			int64_t cap = pr[end] - pr[begin - 1];
			intervals.push_back({cnt, cap});
			sum += cnt * cap;
		}
		if (events[i].is_end) --cnt;
		else ++cnt;
	}
	sort(intervals.begin(), intervals.end(), cmp2);

	//for (auto &in : intervals) {
	//	cout << in.coef << " " << in.capacity << endl;
	//}

	uint64_t i	   = 0;
	int64_t	 diff  = 0;
	while (k > 0 && i < intervals.size()) {
		if (k >= intervals[i].capacity) {
			k -= intervals[i].capacity;
			diff += intervals[i].capacity * intervals[i].coef;
		} else {
			diff += k * intervals[i].coef;
			k = 0;
		}
		++i;
	}
	cout << sum - diff << endl;
}
