#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    vector<pair<long long, double>> indexAndPrice(k);
    vector<double> q(k);
    for (int i = 0; i < k; i++)
    {
        cin >> q[i] >> indexAndPrice[i].second;
        indexAndPrice[i].first = i;
    }
    struct
    {
        bool operator()(pair<long long, double> a, pair<long long, double> b) const
        {
            return a.second < b.second;
        }
    } customLess;
    sort(indexAndPrice.begin(), indexAndPrice.end(), customLess);
    double sum = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        if (n == 0)
        {
            break;
        }
        long long index = indexAndPrice[i].first;
        if (q[index] < n)
        {
            sum += indexAndPrice[i].second * q[index];
            n -= q[index];
        }
        else
        {
            sum += indexAndPrice[i].second * n;
            q[index] = n;
            n = 0;
        }
    }
    cout << fixed << setprecision(2) << sum << endl;
    for (int i = 0; i < k; i++)
    {
        cout << fixed << setprecision(3) << q[i] << endl;
    }
}