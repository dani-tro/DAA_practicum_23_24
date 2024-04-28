#include <iostream>

using namespace std;

#define MAX 100100

int n, k;
long long a[MAX], sum;

long long possible(int dist)
{
    int cnt = 1;
    int curr = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        curr += a[i];
        if (curr > dist)
        {
            ++cnt;
            curr = 0;
        }
    }
    return cnt;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    long long l = 1;
    long long r = sum;

    while (l < r)
    {
        long long mid = (l + r) / 2;
        if (possible(mid) > k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << endl;
    return 0;
}