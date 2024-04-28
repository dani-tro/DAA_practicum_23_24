#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
	long long coord;
	long long type;

	bool operator<(Event const& other) const {
		return coord < other.coord
			|| coord == other.coord && type > other.type;
	}
};

struct Part {
	long long l, r;
	long long segments;

	bool operator<(Part const& other) const {
		return segments > other.segments;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	long long n, m, k;
	std::cin >> n >> m >> k;
	std::vector<long long> a(1, 0);
	for (int i = 0; i < n; i++) {
		long long ai;
		std::cin >> ai;
		a.push_back(ai);
	}

	std::vector<Event> e;
	for (int i = 0; i < m; i++) {
		long long l, r;
		std::cin >> l >> r;

		e.push_back({ l, 1 });
		e.push_back({ r, -1 });
	}
	std::sort(e.begin(), e.end());

	std::vector<Part> p;

	long long previous = 0;
	long long currCount = 0;
	for (Event& ev : e) {
		if (ev.type == 1 && previous < ev.coord - 1) {
			p.push_back({ previous, ev.coord - 1, currCount });
		}
		else if (previous < ev.coord) {
			p.push_back({ previous, ev.coord, currCount });
		}

		currCount += ev.type;

		if (ev.type == 1) {
			previous = ev.coord;
		}
		else {
			previous = ev.coord + 1;
		}
	}
	p.push_back({ previous, n, 0 });

	std::sort(p.begin(), p.end());
	long long s = p.size();

	long long result = 0;
	long long currP = 0;
	
	while (currP < s) {
		for (long long i = p[currP].l; i <= p[currP].r; i++) {
			while (k > 0 && a[i] > 0) {
				k--;
				a[i]--;
			}
			result += a[i] * p[currP].segments;
		}
		currP++; 
	}


	std::cout << result << std::endl;

	return 0;
}