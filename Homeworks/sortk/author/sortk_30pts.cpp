#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(const vector<int> &v){
	for(int i = 0; i + 1 < v.size(); i ++){
		if(v[i] > v[i + 1]) return false;
	}
	return true;
}

int main(){
	int n, k; cin >> n >> k;
	vector<int> A(n);
	for(auto &x : A) cin >> x;
	ll inv = 0;
	while(true){
		bool flag = false;
		for(int i = 0; i + k < n; i ++){
			if(A[i] > A[i + k]){
				++ inv;
				flag = true;
				swap(A[i], A[i + k]);
			}
		}
		if(!flag) break;
	}
	cout << (check(A) ? inv : -1) << endl;
}
