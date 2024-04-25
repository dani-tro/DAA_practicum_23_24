// problem: https://codeforces.com/contest/782/problem/B
#include<bits/stdc++.h>
#define all(A) A.begin(), A.end()
using namespace std;
int n;
vector<double> X, V;
int main(){
	cin >> n;
	X.resize(n);
	V.resize(n);
	for(auto &x : X) cin >> x;
	for(auto &x : V) cin >> x;
	double l = 0, r = 1e10, ans = 0;
	for(int i = 0; i < 100; i ++){
		double m = (l + r) / 2;
		vector<pair<double, double>> v;
		for(int i = 0; i < n; i ++){
			v.push_back({X[i] - V[i] * m, X[i] + V[i] * m});
		}
		pair<double, double> is = {-1, 0};
		for(auto [x, y] : v){
			if(is.first == -1){
				is = {x, y};
			}
			else{
				is.first = max(is.first, x);
				is.second = min(is.second, y);
			}
		}
		if(is.first <= is.second){
			ans = m;
			r = m;
		}
		else{
			l = m;
		}
	}
	cout << fixed << setprecision(12) << ans << endl;
}
