#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[10'010];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    sort(a, a + n);
    
    int left, right = 0, max_len = 0;
    for (left = 0; left < n; ++left)
    {
        while (right < n && a[right] - a[left] <= k)
            ++right;
        max_len = max(right - left, max_len);
    }

    cout << max_len << endl;
    return 0;
}