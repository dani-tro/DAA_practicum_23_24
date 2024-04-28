#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, k, pref[MAXN + 5], dist[MAXN + 5];

int jmp(int pos, int d){
	int l = pos, r = n, ans = -1;
	while(l <= r){
		int m = (l + r) / 2;
		if((m ? pref[m - 1] : 0) - (pos ? pref[pos - 1] : 0) <= d){
			ans = m;
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}
	return ans;
}

int check(int x){
	int pos = 1, ret = 0;
	while(pos <= n){
		pos = jmp(jmp(pos, x), x) + 1;
		++ ret;
	}
	return ret;
}

int main(){
	cin >> n >> k;
	for(int i = 1; i < n; i ++){
		cin >> dist[i];
		pref[i] = pref[i - 1] + dist[i];
	}
	int l = 0, r = pref[n - 1], ans = -1;
	while(l <= r){
		int m = (l + r) / 2;
		if(check(m) <= k){
			ans = m;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	cout << ans << endl;
}
