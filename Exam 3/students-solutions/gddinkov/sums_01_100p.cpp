#include <bits/stdc++.h>


bool possible[101];
bool possible2[101];
long long nums[101];



int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, a, b; std::cin >> n >> a >> b;
	
	
	
	for(int i = 0; i < n; ++i){
		std::cin >> nums[i];
	}
	
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 101; ++j){
			possible2[j] = 0;
		}
		possible2[nums[i]] = 1;
		for(int j = nums[i] + 1; j <= 101	; ++j){
			if(possible[j - nums[i]]){
				possible2[j] = 1;
			}
		}
		for(int j = 0; j < 101; ++j){
			if(1 == possible2[j]) possible[j] = 1;
		}
		
	}
	
	
	int total = 0;
	
	
	
	for(int i = a; i <= b; ++i){
		total += possible[i];
		
		
	}
	
	
	std::cout << total << std::endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
	
	
	
	
}