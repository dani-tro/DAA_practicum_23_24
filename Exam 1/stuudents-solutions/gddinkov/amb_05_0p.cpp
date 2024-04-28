#include <iostream>

long long dists[100001];

bool check(int n, int k, int d, bool b = 0){
	long long curr_limit = d;
	long long curr_covered = 0;
	
	for(int i = 0; i < n - 1; ++i){
		if(dists[i+1] > curr_limit){
			--k;
			curr_limit = dists[i+1] + d;
			curr_covered = dists[i] + d;
		}
	}
	
	if(curr_covered < dists[n-1]){
		--k;
	}
	
	return k >= 0;
	
	
}


int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int min = 0, max = 1000000000;
	int n, k; std::cin >> n >> k;
	for(int i = 1; i < n; ++i){
		std::cin >> dists[i];
		dists[i] += dists[i-1];
	}
	
	
	
	while(min < max - 1){
		int mid = (min + max) / 2;
		dists[n] = dists[n-1] + mid;
		if(check(n, k, mid)){
			max = mid;
		}
		else{
			min = mid;
		}
	}
	
	//check(n, k, 7, 1);
	
	
	std::cout << (check(n, k, min) ? min : max);
	
	
	
	
}