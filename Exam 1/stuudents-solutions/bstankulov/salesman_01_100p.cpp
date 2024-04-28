# include <bits/stdc++.h>
using namespace std;

#define MAX 100000
double capacity;
int n;
pair<double, pair<double, int>> a[MAX];
double sp[MAX];

bool comp(const pair<double, pair<double, int>> &p1, const pair<double, pair<double, int>> &p2) {
    return p1.first > p2.first;
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> capacity >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second.first >> a[i].first;
        a[i].second.second = i;
    }
    sort(a, a + n, comp);
    double total = 0; 
    for (int i = 0; i < n; ++i) {
        if (capacity - a[i].second.first >= 0) {
            capacity -= a[i].second.first;
            total += a[i].second.first * a[i].first;
            sp[a[i].second.second] = a[i].second.first;
        } else {
            total += capacity * a[i].first;
            sp[a[i].second.second] = capacity;
            cout << fixed << setprecision(2) << total << endl;
            for (int j = 0; j < n; ++j) {
                cout << fixed << setprecision(3) << sp[j] << endl;
            }
            return 0;
        }
    }
    cout << fixed << setprecision(2) << total << endl;
    for (int j = 0; j < n; ++j) {
        cout << fixed << setprecision(3) << sp[j] << endl;
    }
    return 0; 
}