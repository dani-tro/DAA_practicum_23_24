#include<bits/stdc++.h>
#define ll long long
#define all(A) A.begin(), A.end()
using namespace std;

const ll INF = 1e15;

ll cnt_lasers, cnt_points;
vector<pair<ll, ll>> lasers, points;
vector<ll> min_S;

ll bs_lower(vector<ll> &v, ll x){
	int l = 0, r = v.size() - 1, idx = -1;
	while(l <= r){
		int m = (l + r) / 2;
		if(v[m] <= x){
			idx = m;
			l = m + 1;
		}
		else{
			r = m - 1;
		}
	}
	if(idx == -1) return INF;
	else return x - v[idx];
}

ll bs_upper(vector<ll> &v, ll x){
	int l = 0, r = v.size() - 1, idx = -1;
	while(l <= r){
		int m = (l + r) / 2;
		if(v[m] >= x){
			idx = m;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	if(idx == -1) return INF;
	else return v[idx] - x;
}

int main(){
	cin >> cnt_lasers >> cnt_points;
	lasers.resize(cnt_lasers);
	points.resize(cnt_points);
	for(auto &[x, y] : lasers){
		cin >> x >> y;
	}
	for(auto &[x, y] : points){
		cin >> x >> y;
	}
	vector<ll> lasers_x, lasers_y;
	for(auto [x, y] : lasers){
		lasers_x.push_back(x);
		lasers_y.push_back(y);
	}
	sort(all(lasers_x));
	sort(all(lasers_y));
	for(auto [x, y] : points){
		ll min_delta_x = min(bs_lower(lasers_x, x), bs_upper(lasers_x, x));
		ll min_delta_y = min(bs_lower(lasers_y, y), bs_upper(lasers_y, y));
		min_S.push_back(min(min_delta_x, min_delta_y));
	}
	sort(all(min_S));
	ll queries; cin >> queries;
	for(int i = 0; i < queries; i ++){
		ll s; cin >> s;
		s /= 2;
		int l = 0, r = min_S.size() - 1, ans = 0;
		while(l <= r){
			int m = (l + r) / 2;
			if(min_S[m] <= s){
				ans = m + 1;
				l = m + 1;
			}
			else{
				r = m - 1;
			}
		}
		cout << ans << " ";
	}
	cout << endl;
}
