#include <bits/stdc++.h>

using namespace std;

int m, n, k;

int sum(vector<pair<int, int>> &vec)
{
    int result{};
    for (auto &x : vec)
    {
        result += (x.first * x.second);
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    vector<int> mount(n);
    for (int &x : mount)
    {
        cin >> x;
    }

    map<int, int> indices;
    int l, r;
    for (int i = 0; i < m; i++)
    {

        cin >> l >> r;
        for (int j = l; j <= r; j++)
        {
            indices[j]++;
        }
    }


    vector<pair<int, int>> a;

    for (auto &x : indices)
    {
        a.push_back({x.first, x.second});
    }

    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second > b.second; });

    int begin = 0;

    if (k < a[0].first)
    {
        a[0].first -= k;
    }
    else
    {
        while (k > 0)
        {
            int temp = a[begin].first;
            a[begin].first = 0;
            k -= temp;
            begin++;
        }
    }
    cout << sum(a) << endl;

    return 0;
};