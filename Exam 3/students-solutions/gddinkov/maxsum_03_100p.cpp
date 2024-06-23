#include <bits/stdc++.h>


int max_l_ending_at[100001];
int max_r_ending_at[100001];
int max_l_ending_below[100001];
int max_r_ending_above[100001];
bool reachable_l[100001];
bool reachable_r[100001];

int nums[100001];
int a[1000];


int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	
	
	int n, k; std::cin >> n >> k;
	
	for(int i = 1; i <= n; ++i){
		std::cin >> nums[i];
	}
	
	for(int i = 0; i < k; ++i){
		std::cin >> a[i];
	}
	
	
	max_l_ending_at[1] = nums[1];
	max_r_ending_at[n] = nums[n];
	reachable_l[1] = 1;
	reachable_r[n] = 1;
	
	for(int i = 2; i <= n; ++i){
		max_l_ending_at[i] = INT_MIN;
		for(int j = 0; j < k; ++j){
			if( i - a[j] >= 1 and reachable_l[i - a[j]]){
				reachable_l[i] = 1;
				max_l_ending_at[i] = std::max(max_l_ending_at[i], max_l_ending_at[i - a[j]] + nums[i]);
			}
		}
		
	}
	
	
	for(int i = n-1; i >= 1; --i){
		max_r_ending_at[i] = INT_MIN;
		for(int j = 0; j < k; ++j){
			if(i + a[j] <= n and reachable_r[i + a[j]]){
				reachable_r[i] = 1;
				max_r_ending_at[i] = std::max(max_r_ending_at[i], max_r_ending_at[i + a[j]] + nums[i]);
			}
		}
		
	}
	
	max_l_ending_below[1] = max_l_ending_at[1];
	
	for(int i = 2; i <= n; ++i){
		max_l_ending_below[i] = std::max(max_l_ending_at[i], max_l_ending_below[i-1]);
	}
	
	max_r_ending_above[n] = max_r_ending_at[n];
	
	for(int i = n - 1; i >= 1; --i){
		max_r_ending_above[i] = std::max(max_r_ending_above[i+1], max_r_ending_at[i]);
	}
	
	
	int max_sum = INT_MIN;
	
	
	for(int i = 1; i <= n-1; ++i){
		max_sum = std::max(max_sum, max_l_ending_below[i] + max_r_ending_above[i+1]);
	}
	
	
	
	std::cout << max_sum << std::endl;
	
	
	return 0;
	
	
	
	
}