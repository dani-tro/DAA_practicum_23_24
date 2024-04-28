#include <bits/stdc++.h>
using namespace std;
uint32_t n,k;
uint32_t get_components(const vector<uint64_t>& dists, uint64_t try_search)
{
    uint32_t ans = 0;

    uint64_t last = dists[0];

    for (size_t i = 1; i < n; i++)
    {
        if(dists[i] - last > try_search)
        {
            last = dists[i - 1];
            ans++;
        }
    }
    // ans++;
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> n>> k;

    vector<uint64_t> dists(n,0);
    dists[0] = 0;

    for (size_t i = 1; i < n; i++)
    {
        uint64_t x;
        cin >> x;
        dists[i] = dists[i-1]+x;
    }
    
    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << dists[i] << " ";
    // }cout << endl; 
    
    // for (size_t i = 1; i <= 10; i++)
    // {
    //    cout << (get_components(dists, i) <= k) <<endl;
    // }
//  cout << (get_components(dists, 1) <= k) <<endl;
    uint64_t l = 1, r = 1e9, mid, ans;
    
    while(l <= r)
    {
        mid = (l+r)/2;
        if(get_components(dists,mid) <= k)
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;


    return 0;
}
/*
4 2
3 5 2
0 3 8 10

6 1
2 2 2 2 2

5 3
1 5 100 1000
*/