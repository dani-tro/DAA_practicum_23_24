// problem: https://pesho.org/assignments/4337/tasks/3
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<array<int, 3>> events;

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i ++){
		int l, r, c; cin >> l >> r >> c;
		events.push_back({l, 1, c});
		events.push_back({r, 3, (r - l + 1) % 2 == 0 ? -c : +c});
	}
	for(int i = 0; i < m; i ++){
		int p; cin >> p;
		events.push_back({p, 2, i});
	}
	sort(events.begin(), events.end());
	long long plus = 0, minus = 0;
	vector<long long> ans(m);
	int last = 0;
	for(auto [pos, type, val] : events){
		if((pos - last) % 2 == 1){
			swap(plus, minus);
		}
		if(type == 1){
			plus += val;
		}
		if(type == 2){
			ans[val] = plus - minus;
		}
		if(type == 3){
			if(val > 0) plus -= val;
			if(val < 0) minus += val;
		}
		last = pos;
	}
	for(auto x : ans){
		cout << x << endl;
	}
}
