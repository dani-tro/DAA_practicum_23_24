#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 100003
using namespace std;
typedef unsigned long long ll;
ll n, k;
ll dist[MAXN];
ll sum = 0;

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> dist[i];
        sum += dist[i];
    }
}

bool eval(ll d)
{
//    ll total = sum;
//    ll left_covered = 0;
//    ll right_covered = 0;
//    cout << endl << endl;
//    cout << d << ": " << endl;
    ll between = sum;

    ll left_tmp = 0;
    ll right_tmp = 0;
    int placed = 0;
    int l = 0;
    int r = n - 1;
    int last_l = -1;
    int last_r = -1;

    while (l < r && between > 2 * d)
    {
        left_tmp += dist[l];
        if (left_tmp > d)
        {
//            left_covered += left_tmp - dist[l];
//            cout << "left: " << l << endl;
            last_l = l;
            between -= left_tmp;
            between += dist[l];
            ++placed;
            left_tmp = dist[l];
        }

        if (between <= 2 * d)
            break;

        right_tmp += dist[r - 1];
        if (right_tmp > d)
        {
//            cout << "right: " << r << endl;
            last_r = r;
            between -= right_tmp;
            between += dist[r - 1];
            ++placed;
            right_tmp = dist[r - 1];
        }

        --r;
        ++l;
    }

    if (last_l < last_r - 1)
    {
        left_tmp = 0;
        for (l = last_l; l < last_r; ++l)
        {
            if (left_tmp + dist[l] <= d)
            {
                left_tmp += dist[l];
            }
            else
                break;
        }

        if (between - left_tmp > d)
            ++placed;
    }

    return placed <= k;
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

    if (tmp >= d)
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
        if (eval(mid))
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

11 3
3 3 3 3 3 3 3 3 3 3


*/

