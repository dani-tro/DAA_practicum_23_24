#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxn = 1e6;
vector<int> arr[maxn];
bool visited[maxn];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, m;
    cin >> n >> m;
    int u, v;
    assert(1 <= n && n <= 1e6);
    assert(1 <= m && m <= 1e6);
    assert(m <= n*(n-1)/2);
    
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        assert(0 <= u);
        assert(u < n);
        assert(0 <= v);
        assert(v < n);
    }
    assert(!(cin >> u));
}
