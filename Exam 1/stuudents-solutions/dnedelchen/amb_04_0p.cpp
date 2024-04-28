#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100003
using namespace std;
typedef long long ll;
ll n, k;
ll dist[MAXN];

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
        cin >> dist[i];
}

bool check(ll d)
{
    ll tmp = 0;
    ll placed = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (tmp + dist[i] <= d)
            tmp += dist[i];
        else
        {
            ++placed;
            tmp = dist[i];
        }
    }

    if (tmp > d)
        ++placed;

    return placed <= k;
}

void solve()
{
    ll l = 0, r = 0, mid;
    for (int i = 0; i < n - 1; ++i)
    {
        r += dist[i];
//        l = max(dist[i], l);
    }

    while (l < r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << r << endl;
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

4 2
3 5 2

6 2
10 10 10 10 10

5 1
4 5 6 7



*/

