#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for(auto &x : A) cin >> x;
	sort(A.begin(), A.end());
	int ans = 0;
	for(int i = 0; i < n; i ++){
		int ptr = i, cnt = 1;
		while(ptr + 1 < n && (A[ptr + 1] == A[ptr] || A[ptr + 1] - A[ptr] <= k)){
			if(A[ptr + 1] != A[ptr]) ++ cnt;
			++ ptr;
		}
		ans = max(ans, cnt);
		i = ptr;
	}
	cout << ans << endl;
}