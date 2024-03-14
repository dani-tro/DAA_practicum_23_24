#include<bits/stdc++.h>
using namespace std;



int main(){
	string t; cin >> t;
	int k; cin >> k;
	int ans = 0;
	for(int left = 0, right = -1, cnt0 = 0, cnt1 = 0; left < t.size(); ){
		while(right + 1 < t.size() && cnt0 + (t[right + 1] == '0') <= k){
			++ right;
			cnt0 += (t[right] == '0');
			cnt1 = (t[right] == '0' ? 0 : cnt1 + 1);
		}
		if(cnt0 == k) ans += cnt1 + 1;
		cnt0 -= (t[left] == '0');
		if(cnt0 == 0 && t[left] == '1') -- cnt1;
		++ left;
	}
	cout << ans << endl;
}