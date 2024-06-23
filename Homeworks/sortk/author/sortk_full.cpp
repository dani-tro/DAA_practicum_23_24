#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl '\n'
#define all(A) A.begin(), A.end()
using namespace std;

template<class T> using matrix = vector<vector<T>>;

ll merge_sort(vector<int> &v, int l, int r){
	if(l == r) return 0;
	int m = (l + r) / 2;
	ll inv = merge_sort(v, l, m) + merge_sort(v, m + 1, r);
	vector<int> left(m - l + 1), right(r - m), sorted(r - l + 1);
	int left_ptr = 0, right_ptr = 0, sorted_ptr = 0;
	for(int i = l; i <= m; i ++){
		left[i - l] = v[i];
	}
	for(int i = m + 1; i <= r; i ++){
		right[i - (m + 1)] = v[i];
	}
	while(left_ptr < left.size() || right_ptr < right.size()){
		if(left_ptr == left.size()){
			sorted[sorted_ptr ++] = right[right_ptr ++];
		}
		else if(right_ptr == right.size()){
			sorted[sorted_ptr ++] = left[left_ptr ++];
		}
		else if(right[right_ptr] < left[left_ptr]){
			inv += left.size() - left_ptr;
			sorted[sorted_ptr ++] = right[right_ptr ++];
		}
		else{
			sorted[sorted_ptr ++] = left[left_ptr ++];
		}
	}
	for(int i = l; i <= r; i ++){
		v[i] = sorted[i - l];
	}
	return inv;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie();
	int n, k; cin >> n >> k;
	vector<int> inp(n);
	for(auto &x : inp){
		cin >> x;
	}
	matrix<int> rows(k);
	vector<int> idxs(k);
	for(int i = 0; i < n; i ++){
		rows[i % k].pb(inp[i]);
	}
	ll ans = 0;
	for(int i = 0; i < k; i ++){
		ans += merge_sort(rows[i], 0, rows[i].size() - 1);
	}
	sort(all(inp));
	vector<int> tmp;
	for(int i = 0; i < n; i ++){
		tmp.pb(rows[i % k][idxs[i % k] ++]);
	}
	cout << (tmp == inp ? ans : -1) << endl;
}
/*
10 2
7 8 9 10 5 2 3 6 1 4
*/
