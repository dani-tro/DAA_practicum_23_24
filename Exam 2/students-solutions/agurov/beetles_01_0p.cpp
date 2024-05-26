#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
typedef pair<int, int> pii;

int n;
//vector<vector<pll>> graph(MAX, vector<pll>());

struct edge {
    int u, v, w;

    bool operator<(const edge &other) const {
        return w < other.w;
    }
};

unsigned long long pow2(int a) {
    return a * a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> n;
    vector<pii> brumbari(n);
    for (auto &[x, y]: brumbari) {
        cin >> x >> y;
    }
    sort(brumbari.begin(), brumbari.end());

    unsigned long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        cout << brumbari[i].first << " " << brumbari[i].second << endl;
        sum += pow2(brumbari[i].first - brumbari[i + 1].first) + pow2(brumbari[i].second - brumbari[i + 1].second);
    }
    cout << sum;
}
