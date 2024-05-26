#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
typedef pair<unsigned long long, int> pii;
unsigned long long parent[MAX], key[MAX];

int n;

struct edge {
    unsigned long long u, v, w;

    bool operator<(const edge &other) const {
        return w < other.w;
    }
};

unsigned long long pow2(unsigned long long a) {
    return a * a;
}

unsigned long long find(unsigned long long a) {
    if (parent[a] == -1)
        return a;
    return (parent[a] = find(parent[a]));
}

void uni(unsigned long long a, unsigned long long b) {
    a = find(a);
    b = find(b);

    if (key[a] > key[b]) {
        parent[b] = a;
    } else if (key[a] < key[b]) {
        parent[a] = b;
    } else {
        parent[a] = b;
        key[b] = key[b] + 1;
    }
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

    vector<edge> edges;
    for (unsigned long long i = 0; i < n; i++) {
        parent[i] = -1;
        key[i] = 0;
    }

    unsigned long long sum = 0;

    for (unsigned long long i = 0; i < n; i++) {
        for (unsigned long long j = i + 1; j < n; j++) {
            edges.push_back({i, j, pow2(brumbari[i].first - brumbari[j].first) +
                                   pow2(brumbari[i].second - brumbari[j].second)});
        }
    }

    sort(edges.begin(), edges.end());

    for (auto &[u, v, w]: edges) {
        if (find(u) != find(v)) {
            uni(u, v);
            sum += w;
        }
    }
    cout << sum;
}
