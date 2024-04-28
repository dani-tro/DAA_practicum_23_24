# include <bits/stdc++.h>
using namespace std;

#define MAX 100000
int l, r, n, m, a[MAX];
long long k;
pair<int, long long> frequency[MAX];

bool comp(const pair<int, long long> &p1, const pair<int, long long> &p2) {
    return p1.second > p2.second;
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int j;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        for (j = l-1; j <= r-1; ++j) {
            frequency[j].first = j;
            frequency[j].second = frequency[j].second + 1;
        }
    }

    sort(frequency, frequency + n, comp);
    int curr;
    for (int i = 0; i < n; ++i) {
        curr = a[frequency[i].first];
        if (k <= curr) {
            a[frequency[i].first] = curr - k;
            break;
        } else {
            a[frequency[i].first] = 0;
            k = k - curr;
        }
    }

    long long total = 0;

    for (int i = 0; i < n; ++i) {
        total += a[frequency[i].first] * frequency[i].second;
    }

    cout << total << endl;
    return 0; 
}