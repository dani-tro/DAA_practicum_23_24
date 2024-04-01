#include<bits/stdc++.h>
#define pb push_back
#define all(A) A.begin(), A.end()
using namespace std;

const int MAXN = 1e5;

int N, M, ans[MAXN + 5];
vector<array<int, 3>> ev; 

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i ++){
		int l, r, c; cin >> l >> r >> c;
		ev.pb({l, 1, +c});
		ev.pb({r, 3, (l % 2 != r % 2 ? -1 : +1) * c});
	}
	for(int i = 0; i < M; i ++){
		int m; cin >> m;
		ev.pb({m, 2, i});
	}
	sort(all(ev));
	int plus = 0, minus = 0, last = 0;
	for(auto [pos, type, val] : ev){
		if(last % 2 != pos % 2) swap(plus, minus);
		if(type == 1) plus += val;
		if(type == 2) ans[val] = plus - minus;
		if(type == 3){
			if(val < 0) minus += val;
			else plus -= val;
		}
		last = pos;
	}
	for(int i = 0; i < M; i ++){
		cout << ans[i] << endl;
	}
}
