#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
 
#pragma GCC optimization ("O3")
 
#define endl '\n'
#define pb push_back
#define fr first
#define sc second
#define ll long long int
#define ld long double
#define bit(idx) idx&(-idx)
#define bin(x, a) bitset<a>(x)
#define all(A) A.begin(), A.end()
#define de(x) cout << #x << " = " << x << endl;
#define matrix vector<vector<ll>>
#define row vector<ll>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/// find_by_order(x) -> x-th element in the set
/// order_of_key(x)  -> how many elements are smaller than x
 
const int MAXN = 2e5 + 5;
 
ll n, dp[MAXN][2];
matrix G;
 
void dfs(int u = 1, int p = -1){
	for(auto v : G[u]){
		if(v != p){
			dfs(v, u);
		}
	}
	for(auto v : G[u]){
		if(v != p){
			dp[u][0] += dp[v][1];
		}
	}
	for(auto v : G[u]){
		if(v != p){
			dp[u][1] = max(dp[u][1], dp[u][0] - dp[v][1] + dp[v][0] + 1);
		}
	}
}
 
int main(){
	/// ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	G = matrix(n + 1);
	for(int i = 0; i < n - 1; i ++){
		int u, v; cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int i = 1; i <= n; i ++){
		if(G[i].size() == 1){
			dp[G[i][0]][1] = 1;
		}
	}
	dfs();
	cout << max(dp[1][1], dp[1][0]) << endl;
}
/**
5
1 2
1 3
3 4
3 5
 
2
*/
