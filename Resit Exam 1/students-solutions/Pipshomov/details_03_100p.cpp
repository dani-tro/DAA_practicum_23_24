#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long n, p, t, w;
vector<pair<long, long>> c;

bool can(long long mid)
{
    long long made = 0;
    for (auto& pair : c)
    {
        made += (mid - pair.first) / pair.second;
 
        if (made >= p)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> w;
        c.push_back({w, t});
    }

    sort(c.begin(), c.end());

    long long l = 0, r = 1e15, mid, ans;
    while (l < r)
    {
        
        mid = (l + r) / 2;

        if (can(mid))
        {

            r = mid;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;

}

