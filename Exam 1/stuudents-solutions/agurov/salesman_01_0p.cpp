#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
    queue<double> quantity;
    for (int i = k - 1; i >= 0; i--)
    {
        if (n == 0)
        {
            break;
        }
        if (arr[i].first < n)
        {
            sum += arr[i].second * arr[i].first;
            quantity.push(arr[i].first);
            n -= arr[i].first;
        }
        else
        {
            sum += arr[i].second * n;
            quantity.push(n);
            n = 0;
        }
    }
    cout << fixed << setprecision(2) << sum << endl;
    while (!quantity.empty())
    {
        cout << fixed << setprecision(3) << quantity.front() << endl;
        quantity.pop();
    }
}