#include <bits/stdc++.h>
using namespace std;

uint64_t get_inter_sum(uint32_t l, uint32_t r, const vector<uint64_t>& a_pref)
{
    uint64_t res = a_pref[r];

    if(l >= 1)
        res -= a_pref[l];

    return res;
}

void decrease_sum(uint32_t l, uint32_t r, vector<uint64_t>& a_pref, vector<uint64_t>& a, uint64_t& k)
{
    for (size_t i = l; i <= r, k != 0; i++)
    {
        if(a[i] >= k)
        {
            a[i] -= k;
            k = 0;
        }
        else if(a[i] != 0)
        {
            k -= a[i];
            a[i] = 0;
        }
    }
    a_pref[0] = a[0];
    for (size_t i = 1; i < a.size(); i++)
    {
        a_pref[i] = a_pref[i-1] + a[i];
    }
    
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n,m;
    uint64_t k;

    cin >> n >> m >> k;

    vector<uint64_t> a(n,0);
    vector<uint64_t> a_pref(n,0);
    vector<pair<uint32_t, uint32_t>> laps(m, {0,0});


    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i]; 
        if(i == 0)
            a_pref[0] = a[0];
        else
            a_pref[i] = a_pref[i-1] + a[i];
    }
    
    for (size_t i = 0; i < m; i++)
    {
        cin >> laps[i].first >> laps[i].second;
    }

    uint64_t total_sum = 0;
    
    for (size_t i = 0; i < m; i++)
    {
        uint32_t l = laps[i].first - 1;
        uint32_t r = laps[i].second - 1;

        decrease_sum(l,r,a_pref,a,k);

        total_sum+= get_inter_sum(l,r,a_pref);
        
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