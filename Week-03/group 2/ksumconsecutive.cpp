#include<bits/stdc++.h>
using namespace std;



int main(){
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for(auto &x : A) cin >> x;
	int ans = -1;
	for(int i = 0; i < n; ){
		if(A[i] > k){
			++ i;
			continue;
		}
		int j = i;
		while(j < n && A[j] <= k){
			++ j;
		}
		for(int left = i, right = i - 1, sum = 0; left < j; ){
			while(right + 1 < j && sum + A[right + 1] <= k){
				++ right;
				sum += A[right];
			}
			ans = max(ans, sum);
			sum -= A[left];
			++ left;
		}
		i = j;
	}
	cout << ans << endl;
}