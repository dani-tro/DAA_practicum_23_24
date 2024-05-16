#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
const int MAXN = 1e6 + 3;
 
int n, x, dp[MAXN], A[MAXN];
 
int main(){
	cin >> n >> x;
	for(int i = 1; i <= n; i ++){
		cin >> A[i];
	}
	dp[0] = 0;
	for(int i = 1; i <= x; i ++){
		dp[i] = x + 1;
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j <= x; j ++){
			if(j - A[i] >= 0){
				dp[j] = min(dp[j], dp[j - A[i]] + 1);
			}
		}
	}
	cout << (dp[x] == x + 1 ? -1 : dp[x]) << endl;
}
