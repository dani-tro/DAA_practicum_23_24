#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n, k, A[MAXN + 5], cnt[32];

int get(){
	int ret = 0;
	for(int i = 0, v = 1; i < 32; i ++, v *= 2){
		if(cnt[i] > 0){
			ret += v;
		}
	}
	return ret;
}

void add(int x){
	int a = 0;
	while(x > 0){
		if(x % 2 == 1){
			++ cnt[a];
		}
		++ a;
		x /= 2;
	}
}

void rem(int x){
	int a = 0;
	while(x > 0){
		if(x % 2 == 1){
			-- cnt[a];
		}
		++ a;
		x /= 2;
	}
}

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> A[i];
	}
	long long ans = 0;
	for(int l = 1, r = 1; l <= n; /*празно нарочно*/ ){
		while(r <= n && get() < k){
			add(A[r]);
			++ r;
		}
		if(get() >= k){
			ans += (long long)(n - r + 2);
		}
		rem(A[l]);
		++ l;
	}
	cout << ans << endl;
}
