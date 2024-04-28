#include <iostream>
#include <algorithm>

using namespace std;

void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

long long n, m, k;

long long as[100005];

struct inv {
    long long l;
    long long r;

    bool operator<(inv other) {
        return (r-l) < (other.r - other.l);
    }
};

inv invs[1000006];

void minimize(long long l, long long r)
{
    // for(long long i = l; i <= r; i++) {
    //     cout << as[i] << " ";
    // }
    // cout << endl;

    for(long long i = l; i <= r && k > 0; i++) {
        if(as[i] > 0) {
            if(as[i] >= k) {
                as[i] -= k;
                k = 0;
            }
            else {
                as[i] = 0;
                k -= as[i];
            }
        }
    }
}

int main()
{
    fast_IO();

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> as[i];
    }
    for(int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        invs[i] = { a, b };
    }
    sort(invs, invs + m);

    for(int i = 0; i < m; i++) {
        if(k > 0)
            minimize(invs[i].l-1, invs[i].r-1);
    }

    long long sum = 0;
    for(int i = 0; i < m; i++) {
        // cout << invs[i].l-1 << " " << invs[i].r-1 << endl;

        for(long long j = invs[i].l-1; j <= invs[i].r-1; j++) {
            sum += as[j];
        }
    }

    cout << sum << endl;

    return 0;
}