// O(n * log(n))

#include <bits/stdc++.h>

using namespace std;

#define MAX 2100000

int n, a[MAX], b[MAX];


long long merge(int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2, idx = 0;
    long long ans = 0;
    while(i <= r1 && j <= r2)
    {
        if(a[i] >= a[j])
        {
            b[idx] = a[j];
            j++;
            ans += (r1 - i + 1);
        }
        else
        {
            b[idx] = a[i];
            i++;
        }
        idx++;
    }
    for(; i <= r1; i++)
    {
        b[idx] = a[i];
        idx++;
    }
    for(; j <= r2; j++)
    {
        b[idx] = a[j];
        idx++;
    }

    for(int i = l1; i <= r2; i++)a[i] = b[i - l1];
    return ans;
}

long long inversions(int l, int r)
{
    if(l >= r)
    {
        return 0;
    }
    int mid = (l + r) / 2; // l + (r - l) / 2
    long long inv1 = inversions(l, mid);
    long long inv2 = inversions(mid + 1, r);
    return inv1 + inv2 + merge(l, mid, mid + 1, r);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];

    cout << inversions(0, n - 1) << endl;

    return 0;
}
