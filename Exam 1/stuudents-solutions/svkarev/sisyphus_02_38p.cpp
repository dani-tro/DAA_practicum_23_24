#include <bits/stdc++.h>
using namespace std;

uint64_t get_inter_sum(uint32_t l, uint32_t r, const vector<uint64_t> &a_pref)
{
    uint64_t res = a_pref[r];

    if (l >= 1)
        res -= a_pref[l - 1];

    return res;
}

void calc_pref(vector<uint64_t> &a_pref, vector<uint64_t> &a)
{
    a_pref[0] = a[0];
    for (size_t i = 1; i < a.size(); i++)
    {
        a_pref[i] = a_pref[i - 1] + a[i];
    }
}

void decrease_sum(uint32_t l, uint32_t r, vector<uint64_t> &a_pref, vector<uint64_t> &a, uint64_t &k)
{
    uint32_t max_idx = l;
    for (size_t i = l; i <= r && k != 0; i++)
    {
        if (a[max_idx] < a[i])
            max_idx = i;
    }

    if (a[max_idx] >= k)
    {
        a[max_idx] -= k;
        k = 0;
        calc_pref(a_pref, a);
    }
    else if (a[max_idx] != 0)
    {
        k -= a[max_idx];
        a[max_idx] = 0;
        decrease_sum(l, r, a_pref, a, k);
    }
}

struct interval
{
    uint32_t point;
    int type;

    const bool operator<(const interval &other) const
    {
        return point < other.point || (point == other.point && type < other.type);
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n, m;
    uint64_t k;

    cin >> n >> m >> k;

    vector<uint64_t> a(n, 0);
    vector<uint64_t> a_pref(n, 0);
    // vector<interval> laps;
    vector<pair<uint32_t,uint32_t>> intervals(m,{0,0});

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            a_pref[0] = a[0];
        else
            a_pref[i] = a_pref[i - 1] + a[i];
    }

    for (size_t i = 0; i < m; i++)
    {
        cin >> intervals[i].first >> intervals[i].second;
        intervals[i].first -= 1;
        intervals[i].second -= 1;
        // laps.push_back({intervals[i].first - 1, 1});
        // laps.push_back({intervals[i].second - 1, -1});
    }
    // sort(laps.begin(), laps.end());

    uint64_t total_sum = 0;
    uint32_t last_start = 0;

    for (size_t i = 0; i < m; i++)
    {
        if(k != 0)
        {
            decrease_sum(intervals[i].first, intervals[i].second, a_pref, a, k);
            calc_pref(a_pref,a);
        }
        total_sum += get_inter_sum(intervals[i].first, intervals[i].second, a_pref);
    }

    cout << total_sum << endl;

    return 0;
}
/*
4 2 2
1 2 3 4
1 4
3 4
*/  