#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> path(n);
    for (auto &x : path)
    {
        cin >> x;
    }
    vector<long long> times(n, 0);
    for (int i = 0; i < m; i++)
    {
        long long l, r;
        cin >> l >> r;
        for (int j = l - 1; j <= r - 1; j++)
        {
            times[j]++;
        }
    }

    auto cmp = [](pair<long long, long long> left, pair<long long, long long> right)
    { return left.first < right.first; };

    priority_queue<pair<long long, long long>, std::vector<pair<long long, long long>>, decltype(cmp)> pqueue(cmp);

    for (int i = 0; i < n; i++)
    {
        if (times[i] != 0 && path[i] != 0)
        {
            pqueue.push(pair<long long, long long>{times[i], i});
        }
    }
    for (int i = 0; i < k && !pqueue.empty(); i++)
    {
        pair<long long, long long> curr = pqueue.top();
        pqueue.pop();
        path[curr.second]--;
        if (path[curr.second] > 0)
        {
            pqueue.push(curr);
        }
    }
    long long diff = 0;
    for (int i = 0; i < n; i++)
    {
        diff += path[i] * times[i];
    }
    cout << diff << endl;
}