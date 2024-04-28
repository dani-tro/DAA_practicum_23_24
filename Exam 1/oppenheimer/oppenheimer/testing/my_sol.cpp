#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int cnt[MAXN];

int main(){
	int n, k; cin >> n >> k;
	int maxa = 0;
	for(int i = 0; i < n; i ++){
		int x; cin >> x;
		cnt[x] ++;
		maxa = max(maxa, x);
	}
	int cur = 0, ans = 0;
	for(int i = 1; i <= k; i ++){
		cur += cnt[i];
	}
	cout << "1 " << k << ": " << cur << endl;
	ans = cur;
	for(int add = k + 1, rem = 1; add <= maxa; add ++, rem ++){
		cur = cur - cnt[rem] + cnt[add];
		cout << rem + 1 << " " << add << ": " << cur << endl;
		ans = max(ans, cur);
	}
	cout << ans << endl;
}
