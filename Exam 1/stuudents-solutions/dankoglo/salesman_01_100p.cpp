#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

double m;
int n;

double as[105];
double bs[105];

struct item {
    double w;
    double p;

    int idx;

    bool operator>(item other) const
    {
        return p > other.p;
    }
};

item items[105];

double ans[105];

int main()
{
    fast_IO();

    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> as[i] >> bs[i];
        items[i] = { as[i], bs[i], i };
    }
    sort(items, items + n, greater<item>());

    double res = 0;
    for(int i = 0; i < n && m > 0; i++) {
        if(items[i].w > m) {
            res += items[i].p*m;
            ans[items[i].idx] = m;
            m = 0;
        }
        else {
            res += items[i].p*items[i].w;
            m -= items[i].w;
            ans[items[i].idx] = items[i].w;
        }
    }

    cout << fixed << setprecision(2) << res << "\n";
    for(int i = 0; i < n; i++) {
        cout << fixed << setprecision(3) << ans[i] << "\n";
    }

    return 0;
}