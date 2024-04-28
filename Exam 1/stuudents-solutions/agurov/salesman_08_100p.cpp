#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double n;
    long long k;
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
    vector<double> q2(k, 0);

    for (int i = k - 1; i >= 0; i--)
    {
        if (n == 0)
        {
            break;
        }
        long long index = indexAndPrice[i].first;
        double price = indexAndPrice[i].second;

        if (q[index] < n)
        {
            sum += price * q[index];
            q2[index] = q[index];
            n -= q2[index];
        }
        else
        {
            sum += price * n;
            q2[index] = n;
            n = 0;
        }
    }

    cout << fixed << setprecision(2) << sum << endl;
    for (int i = 0; i < k; i++)
    {
        cout << fixed << setprecision(3) << q2[i] << endl;
    }
}