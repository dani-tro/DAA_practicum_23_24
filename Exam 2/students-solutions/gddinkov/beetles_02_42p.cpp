#include <bits/stdc++.h>


using namespace std;


bool done[100000];

unsigned long long dist(unsigned long long x, unsigned long long y, unsigned long long a, unsigned long long b){
	return (x - a) * (x - a) + (y - b) * (y - b);
}



int main(){
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		
		vector<pair<unsigned long long, unsigned long long>> beetles;
		int n; std::cin >> n;
		for(int i = 0; i < n; ++i){
			unsigned long long  x, y; std::cin >> x >> y;
			beetles.push_back({x, y});
		}
		
		done[0] = 1;
		
		auto cmp = [](pair<int, unsigned long long> left, pair<int, unsigned long long> right){ return left.second > right.second; };
		
		std::priority_queue<pair<int, unsigned long long>, vector<pair<int,unsigned long long>>, decltype(cmp)> q{cmp};
		for(int i = 0; i < n; ++i){
			if(!done[i]){
				q.push({i, dist(beetles[0].first, beetles[0].second, beetles[i].first, beetles[i].second)});
			}
		}
		
		unsigned long long total = 0;
		
		while(!q.empty()){
			auto p = q.top();
			q.pop();
			int ind = p.first;
			int d = p.second;
			if(!done[ind]){
				done[ind] = 1;
				total += d;
				for(int i = 0; i < n; ++i){
					if(!done[i]){
						q.push({i, dist(beetles[ind].first, beetles[ind].second, beetles[i].first, beetles[i].second)});
					}
				}
			}
		}
		
		std::cout << total;
		
		
		return 0;
		
			
		
}