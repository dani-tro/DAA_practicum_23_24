#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int result = 1;
    int prevRange = 1;
    for(int i = 0; i < n - 1; i++)
    {
        int count = prevRange;
        for(int j = i + prevRange; j < n; j++)
        {
            if(a[j] - a[i] <= k)
            {
                count++;
            }
            else
                break;
        }
        result = max(result, count);
        prevRange = count;
        
        if(result + i >= n)
            break;
    }

    cout << result;
}