#include <iostream>

int dists[100000];

bool check(int n, int k, int d, bool b = 0){
	int curr = 0;
	int curr_d = 0;
	
	while(curr < n){
		curr_d += dists[curr];
		
		b && (std::cout << curr << " " << curr_d);
		if(curr_d > d){
			b && (std::cout << " here");
			if(k == 0){
				return 0;
			}
			--k;
			curr_d = dists[curr];
		}
		b && (std::cout << std::endl);
		++curr;
		
	}
	
	return 1;
	
	
}


int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int min = 0, max = 1000000000;
	int n, k; std::cin >> n >> k;
	--n;
	for(int i = 0; i < n; ++i){
		std::cin >> dists[i];
	}
	
	while(min < max - 1){
		int mid = (min + max) / 2;
		if(check(n, k, mid)){
			max = mid;
		}
		else{
			min = mid;
		}
	}
	
	//check(n, k, 4, 1);
	
	
	std::cout << (check(n, k, min) ? min : max);
	
	
	
	
}