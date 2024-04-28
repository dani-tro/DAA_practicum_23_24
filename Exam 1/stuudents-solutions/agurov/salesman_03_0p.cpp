#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    vector<pair<double, double>> arr(k);
    for (auto &x : arr)
    {
        cin >> x.first >> x.second;
    }
    struct
    {
        bool operator()(pair<double, double> a, pair<double, double> b) const
        {
            return a.second < b.second;
        }
    } customLess;
    sort(arr.begin(), arr.end(), customLess);
    double sum = 0;
    vector<double> quantity(k);
    for (int i = k - 1; i >= 0; i--)
    {
        if (n == 0)
        {
            break;
        }
        if (arr[i].first < n)
        {
            sum += arr[i].second * arr[i].first;
            quantity[i] = arr[i].first;
            n -= arr[i].first;
        }
        else
        {
            sum += arr[i].second * n;
            quantity[i] = n;
            n = 0;
        }
    }
    cout << fixed << setprecision(2) << sum << endl;
    for (int i = k - 1; i >= 0; i--)
    {
        cout << fixed << setprecision(3) << quantity[i] << endl;
    }
}