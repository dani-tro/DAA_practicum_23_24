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
	for(int i = 0; i < N; i ++){
		for(int j = i; j < N; j ++){
			if(A[j] <= A[i] + K){
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans << endl;
}
