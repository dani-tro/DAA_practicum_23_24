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
	for(int l = 0, r = 0; l < N; l ++){
		while(r < N && A[r] <= A[l] + K){
			++ r;
		}
		ans = max(ans, r - l);
	}
	cout << ans << endl;
}
