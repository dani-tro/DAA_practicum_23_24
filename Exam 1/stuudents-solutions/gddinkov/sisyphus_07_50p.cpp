#include <bits/stdc++.h>


struct obj{
	int i;
	int a;
	int freq;
};

obj entries[100001];
//za chestotite
int curr;

// nachalo na interval s prio 0
// indeks na masiva s prio 1
// krai na interval s prio 2
struct callable{
	int i;
	int prio;
	void event(){
		if(prio == 0){
			++curr;
		}
		else if(prio == 1){
			entries[i].freq = curr;
		}
		else{
			--curr;
		}
	};
};



callable points[3000002];
long long a[100001];







int main(){
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n, m; long long k; std::cin >> n >> m >> k;
	unsigned long long total = 0;
	
	
	//inicializira i smqta prefixni sumi
	//prefixnite sumi za burzo smqtane na total
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i];
		entries[i].i = i;
		entries[i].a = a[i];
		a[i] += a[i-1];
		points[i].prio = 1;
		points[i].i = i;
	}
	
	int l, r;
	
	// inicializaciq za sweep line
	for(int i = 0; i < m; ++i){
		std::cin >> l >> r;
		points[n + 2 * i + 1].prio = 0;
		points[n + 2 * i + 1].i = l;
		points[n + 2 * i + 2].prio = 2;
		points[n + 2 * i + 2].i = r;
		total += a[r] - a[l-1];
	}
	
	// sortira po dva klucha
	// nachala predi indeksi predi kraishta
	std::sort(points + 1, points + 1 + n + 2 * m, [](callable x, callable y){ return x.i < y.i or (x.i == y.i and x.prio < y.prio); });
	
	// iterira subitiqta
	for(int i = 1; i <= n + 2 * m; ++i){
		points[i].event();
	}
	
	// sortira indeksite po chestota
	std::sort(entries + 1, entries + 1 + n, [](obj x, obj y){ return x.freq > y.freq; });
	
	// greedy vzema ot nai chestite indeksi dokato moje
	for(int i = 1; i <= n; ++i){
		if(k > entries[i].a){
			k -= entries[i].a;
			total -= entries[i].a * entries[i].freq;
			entries[i].a = 0;
		}
		else{
			total -= k * entries[i].freq;
			entries[i].a -= k;
			break;
		}
	}
	
	total = 0;
	for(int i = 1; i <= n; ++i){
		total += entries[i].a * entries[i].freq;
	}
	
	std::cout << total;
	
	
}