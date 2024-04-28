#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100003
#define MAXM 1000003
using namespace std;
typedef long long ll;
int n, m;
ll arr[MAXN], k;

struct segment
{
    ll cnt;
    int idx;
    bool operator < (const segment &other) const
    {
        return cnt > other.cnt;
    }
};

segment segments[MAXN];
ll sum[MAXN];
int from[MAXM], to[MAXM];

void input()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        segments[i].idx = i;
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> from[i] >> to[i];
        --from[i];
        --to[i];

        ++segments[from[i]].cnt;
        --segments[to[i]].cnt;
    }
}

void solve()
{
    for (int i = 1; i < n; ++i)
        segments[i].cnt += segments[i - 1].cnt;

    sort(segments, segments + n);
    for (int i = 0; i < n && k > 0; ++i)
    {
        if (arr[segments[i].idx] <= k)
        {
            arr[segments[i].idx] = 0;
            k -= arr[segments[i].idx];
        }
        else
        {
            arr[segments[i].idx] -= k;
            k = 0;
            break;
        }
    }

    sum[0] = arr[0];
    for (int i = 1; i < n; ++i)
        sum[i] = arr[i] + sum[i - 1];

    ll total = 0;
    for (int i = 0; i < m; ++i)
    {
        ll tmp = sum[to[i]];
        tmp -= (from[i] == 0 ? 0 : sum[from[i] - 1]);
        total += tmp;
    }

    cout << total << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();

    return 0;
}


/**

4 2 2
1 2 3 4
1 4
3 4

4 2 5
1 2 0 0
1 4
3 4

*/
