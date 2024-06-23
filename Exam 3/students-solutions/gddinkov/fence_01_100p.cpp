#include <bits/stdc++.h>


long long f_l[2001][2001];
long long f_h[2001][2001];
long long f_l_pref[2001][2001];
long long f_h_pref[2001][2001];


long long p = 1000000007;


int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	
	
	long long s; std::cin >> s;
	
	f_l[0][0] = 1;
	f_h[0][0] = 1;
	
	
	f_l_pref[0][0] = 1;
	f_h_pref[0][0] = 1;
	for(int h = 1; h <= s; ++h){
		f_l_pref[0][h] = (f_l_pref[0][h-1] + f_l[0][h]) % p;
		f_h_pref[0][h] = (f_h_pref[0][h-1] + f_h[0][h]) % p;
	}
	
	f_l[1][1] = 1;
	f_h[1][1] = 1;
	
	for(int h = 1; h <= s; ++h){
		f_l_pref[1][h] = (f_l_pref[0][h-1] + f_l[0][h]) % p;
		f_h_pref[1][h] = (f_h_pref[0][h-1] + f_h[0][h]) % p;
	}
	
	for(int i = 2; i <= s; ++i){
		for(int h = 1; h <= i; ++h){
			f_l[i][h] = (f_h_pref[i-h][i] - f_h_pref[i-h][h] + p) % p;
			f_h[i][h] = f_l_pref[i-h][h-1];
		}
		f_l[i][i] = 1;
		
		
		for(int h = 1; h <= s; ++h){
			f_l_pref[i][h] = (f_l_pref[i][h-1] + f_l[i][h]) % p;
			f_h_pref[i][h] = (f_h_pref[i][h-1] + f_h[i][h]) % p;
		}
	}
	
	
	
	
	
	
	long long total = (f_l_pref[s][s] + f_h_pref[s][s]) % p;
	
	
	
	std::cout << total - 1 << std::endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
	
	
	
	
}