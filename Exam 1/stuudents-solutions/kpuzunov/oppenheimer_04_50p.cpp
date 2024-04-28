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
    for(int i = 0; i < n - 1; i++)
    {
        int count = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(abs(a[i] - a[j]) <= k)
            {
                count++;
            }
            else
                break;
        }
        result = max(result, count);
        if(result + i >= n)
            break;
    }

    cout << result;
}