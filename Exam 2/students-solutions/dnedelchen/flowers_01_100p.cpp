#include <bits/stdc++.h>
#define MAXN 20003
#define endl '\n'
using namespace std;
int k;
bool exists[MAXN];
vector<int> flowers;
int arr[MAXN];
int in[MAXN];

vector<int> adj[MAXN];
queue<int> q;

void input()
{
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int cnt;
        cin >> cnt;
        if (!cnt)
            continue;

        for (int j = 0; j < cnt; ++j)
        {
            cin >> arr[j];
            if (!exists[arr[j]])
            {
                exists[arr[j]] = 1;
                flowers.push_back(arr[j]);
            }
        }

        for (int j = 0; j < cnt - 1; ++j)
            adj[arr[j]].push_back(arr[j + 1]);
    }
}

void solve()
{
    int cnt = flowers.size();
//
//    for (int i = 0; i < cnt; ++i)
//    {
//        cout << "flr: " << flowers[i] << endl;
//        for (int j = 0; j < adj[flowers[i]].size(); ++j)
//            cout << adj[flowers[i]][j] << " ";
//        cout << endl;
//    }


    for (int i = 0; i < cnt; ++i)
    {
        int sz = adj[flowers[i]].size();
        for (int j = 0; j < sz; ++j)
            ++in[adj[flowers[i]][j]];
    }

    for (int i = 0; i < cnt; ++i)
        if (!in[flowers[i]])
            q.push(flowers[i]);

    int visited = 0;
    while (!q.empty())
    {
        int tmp = q.front();
//        cout << tmp << " ";
        q.pop();
        ++visited;

        int sz = adj[tmp].size();
        for (int i = 0; i < sz; ++i)
        {
            --in[adj[tmp][i]];
            if (!in[adj[tmp][i]])
                q.push(adj[tmp][i]);
        }
    }

//    cout << endl;

    cout << (visited == cnt) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();

    return 0;
}


/**

2
3 1 2 3
4 1 3 5 6


3
3 5 1 4
3 4 201 150
4 150 1 20 55


2
4 1 5 6 2
3 2 1 6


4
5 100 20 45 10 3
3 20 300 400
4 500 100 80 10
3 400 500 1000


3
3 1 80 5
5 90 1 4 8 80
5 90 1 8 100 5


*/
