#include <bits/stdc++.h>




struct obj{
	double a;
	double b;
	int i;
	double taken;
};

obj entries[100];

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int m, n; std::cin >> m >> n;
	
	for(int i = 0; i < n; ++i){
		std::cin >> entries[i].a >> entries[i].b;
		entries[i].i = i;
	}
	
	std::sort(entries, entries + n, [](obj x, obj y){ return x.b > y.b; });
	
	double total = 0;
	double max_sum = 0;
	
	for(int i = 0; i < n; ++i){
		if(total + entries[i].a < m){
			total += entries[i].a;
			max_sum += entries[i].a * entries[i].b;
			entries[i].taken = entries[i].a;
		}
		else{
			max_sum += (m - total) * entries[i].b;
			entries[i].taken = m - total;
			break;
		}
	}
	
	std::sort(entries, entries + n, [](obj x, obj y){ return x.i < y.i; });
	
	
	std::cout << std::fixed << std::setprecision(2) << max_sum << std::endl;
	
	for(int i = 0; i < n; ++i){
		std::cout << std::fixed << std::setprecision(3) << entries[i].taken << std::endl;
		
	}
	
	
}