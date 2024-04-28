#include <bits/stdc++.h>

int a[100000];



int main(){

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	int n, k; std::cin >> n >> k;
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	
	std::sort(a, a + n);
	
	int start = 0, end = 0;
	int max = 1;
	while(end < n){
		if(a[end] - a[start] <= k){
			++end;
		}
		else{
			if(max < end - start){
				max = end - start;
			}
			++start;
		}
	}
	
	if(end - start > max){
		max = end - start;
	}
	
	std::cout << max;
	
}