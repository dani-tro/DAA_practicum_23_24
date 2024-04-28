#include<bits/stdc++.h>
#define all(A) A.begin(), A.end()
using namespace std;



int main(){
	int N, K; cin >> N >> K;
	vector<int> A(N);
	for(auto &x : A){
		cin >> x;
	}
	sort(all(A));
	int ans = 0;
	for(int l = 0, r = -1; l < N; l ++){
		while(r + 1 < N && A[r + 1] <= A[l] + K){
			++ r;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
}
