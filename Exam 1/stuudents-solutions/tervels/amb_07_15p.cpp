#include <iostream>
using namespace std;

int n, k;
unsigned long long d[100'010], l, r, mid, opt;

bool couldSolve(int dist)
{
    int sum = 0, tv_count = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = i;
        sum = 0;

        while (j < n && sum + d[j] <= dist)
        {
            sum += d[j];
            ++j;
        }
        ++tv_count;
        if (j == i)
            continue;
        sum = 0;
        while (j < n && sum + d[j] <= dist)
        {
            sum += d[j];
            ++j;
        }
        i = j - 1;
    }

    return tv_count <= k;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> d[i];
        l = min(l, d[i]);
        r += d[i];
    }

    opt = r;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (couldSolve(mid))
        {
            opt = min(mid, opt);
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    
    cout << opt << endl;
    
    return 0;
}