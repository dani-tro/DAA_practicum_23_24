#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, a[100001], c[100001], l[100001], r[100001];

struct endpoint {
    int value;
    bool isClosing;
    int index;
    
    endpoint() : value(0), isClosing(false), index(-1) {}
    endpoint(int value, bool isClosing, int index) : value(value), isClosing(isClosing), index(index) {}

    bool operator<(const endpoint& other) const {
        if (value < other.value) return true;
        if (value == other.value) return isClosing == false;
        return false;
    }
};

struct point_passing {
    int value;
    int opened;
    
    point_passing() : value(0), opened(0) {}
    point_passing(int value, int opened) : value(value), opened(opened) {}

    bool operator<(const point_passing& other) const {
        return opened > other.opened;
    }
};

endpoint points[1000001];
point_passing points_passing[100001];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int d, b;
    for(int i = 0; i < m; i++) {
        cin >> d >> b;
        l[i] = d;
        r[i] = b;
        points[2*i] = endpoint(d, false, i);
        points[2*i + 1] = endpoint(b, true, i);
    }

    sort(points, points + 2*m);

    int opened = 0;
    for(int i = 0; i < 2*m; i++) {
        points_passing[points[i].value].value = points[i].value;
        if (points[i].isClosing == false) {
            opened++;
            points_passing[points[i].value].opened = opened;
        } else {
            if (points_passing[points[i].value].opened < opened) points_passing[points[i].value].opened = opened;
            opened--;
        }
    }

    sort(points_passing, points_passing + n + 1);
    for(int i = 0; i <= n; i++) {
        if (k == 0 || points_passing[i].opened == 0) break;
        if (a[points_passing[i].value] > 0) {
            if (points_passing[i].opened > a[points_passing[i].value]) {
                k -= a[points_passing[i].value];
                a[points_passing[i].value] = 0;
            } else if(k > points_passing[i].opened) {
                a[points_passing[i].value] -= points_passing[i].opened;
                k -= points_passing[i].opened;
            } else {
                a[points_passing[i].value] -= k;
                k = 0;
            }
        }
    }

    if (k > 0) {
        for(int i = 1; i <= n; i++) {
            if (a[i] > 0 && a[i] >= k) {
                a[i] -= k;
                k = 0;
                break;
            } else if (a[i] > 0 && a[i] < k) {
                a[i] = 0;
                k -= a[i];
            }
        }
    }

    int prefixSum[n];
    prefixSum[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    
    int sum = 0;
    for(int i = 0; i < m; i++) {
        sum += prefixSum[r[i]] - prefixSum[l[i] - 1];
    }

    cout << sum << endl;
}