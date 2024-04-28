#include <bits/stdc++.h>
using namespace std;

#define MAX 101000

int n, k, a[MAX], i, j, idx, max_length;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n + 1);
    j = 1;

    for(int i = 1; i <= n; i++)
    {
        j = max(j, i);

        while (j + 1 <= n && a[j + 1] - a[i] <= k)
        {
            j++;
        }

        if (max_length < j - i + 1)
        {
            max_length = j - i + 1;
            idx = i;
        }        
    }
    
    cout << max_length << endl;

    return 0;
}