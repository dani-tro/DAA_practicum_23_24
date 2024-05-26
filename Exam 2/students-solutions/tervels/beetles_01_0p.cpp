#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;
const int MAXN = 2e4 + 5;
set<int> g[MAXN];
set<int> vertices;
int in[MAXN];

vector<int> answer;

int k, n, a;

int main()
{
    cin >> k;
    int u, prev;
    for (int i = 0; i < k; ++i)
    {
        cin >> n;
        cin >> u;
        vertices.insert(u);
        prev = u;
        for (int i = 2; i <= n; ++i)
        {
            cin >> u;
            vertices.insert(u);
            bool inserted = g[prev].insert(u).second;
            if (inserted)
                ++in[u];
            prev = u;
        }
    }
    queue<int> q;
    for (auto s : vertices)
        if (in[s] == 0) q.push(s);

    //cout << "napylnih opashkata\n" << q.size() << endl;
    
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        answer.push_back(curr);

        for (auto u : g[curr])
        {
            --in[u];
            if (in[u] == 0) q.push(u);
        }

        //cout << "hello\n";
    }

    cout << (answer.size() == vertices.size()) << endl;

    return 0;
}