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

struct Elem {
    long long data;
    long long segments = 0;

    bool operator<(Elem const& other) {
        return segments > other.segments
            || segments == other.segments && data > other.data;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n, m, k;
    std::cin >> n >> m >> k;
    std::vector<Elem> a(1, { 0 , 0 });
    for (int i = 0; i < n; i++) {
        long long ai;
        std::cin >> ai;
        a.push_back({ ai });
    }

    std::vector<Event> e;
    for (int i = 0; i < m; i++) {
        long long l, r;
        std::cin >> l >> r;

        e.push_back({ l, 1 });
        e.push_back({ r, -1 });
    }
    std::sort(e.begin(), e.end());

    long long previous = 1;
    long long currCount = 0;
    for (Event& ev : e) {
        if (ev.type == 1 && previous <= ev.coord - 1) {
            for (int i = previous; i <= ev.coord - 1; i++) {
                a[i].segments = currCount;
            }
        }
        else if (previous <= ev.coord) {
            for (int i = previous; i <= ev.coord; i++) {
                a[i].segments = currCount;
            }
        }

        currCount += ev.type;

        if (ev.type == 1) {
            previous = ev.coord;
        }
        else {
            previous = ev.coord + 1;
        }
    }
    for (int i = previous; i <= n; i++) {
        a[i].segments = 0;
    }
    std::sort(a.begin(), a.end());

    long long result = 0;
 
    for (int i = 0; i < n; i++) {
        while (k > 0 && a[i].data > 0) {
            k--;
            a[i].data--;
        }
        result += a[i].data * a[i].segments;
    }

    std::cout << result << std::endl;

    return 0;
}