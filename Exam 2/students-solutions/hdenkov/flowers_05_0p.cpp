#include <bits/stdc++.h>
using namespace std;

#define MAXK 105
#define MAXN 20020

int k, n, f, ans = 0;
vector<int> garden[MAXK];
// vector<set<int>> garden;
int in[MAXN];
set<int> flower;

queue<int> q;

void toposort()
{
    bool tech = false;
    for (auto f : flower)
    {
        if (in[f] == 0)
        {
            tech = true;
            q.push(f);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans++;

        for (auto p : garden[curr])
        {
            cout << p << ' ';
            in[p]--;
            if (in[p] == 0)
                q.push(p);
        }
        cout << endl;
    }
}

int main()
{
    cin >> k;

    int i, j, prev, curr;

    for (i = 0; i < k; ++i)
    {
        cin >> n;
        for (j = 0; j < n; ++j)
        {
            cin >> f;
            curr = f;
            if (j != 0)
            {
                garden[prev].push_back(curr);
                // garden[prev].insert(curr);
                in[curr]++;
            }
            flower.insert(f);
            prev = f;
        }
    }

    // toposort();

    cout << (ans == flower.size()) << endl;
}
