#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;

const int MAXA = 1e3;

int main(int argc, char **argv){
	registerGen(argc, argv, 1);
	int n = opt<int>(1), k = opt<int>(2);
	string type = opt<string>(3);
	if(type == "const"){
		cout << n << " " << k << endl;
		int c = rnd.next(1, MAXA);
		for(int i = 1; i < n; i ++){
			cout << c << " ";
		}
		cout << endl;
	}
	if(type == "binary"){
		assert(n <= 30);
		cout << n << " " << k << endl;
		for(int i = 1, x = 2; i < n; i ++, x *= 2){
			cout << x << " ";
		}
		cout << endl;
	}
	if(type == "restricted"){
		n = rnd.next(1, MAXA);
		vector<int> split = {0};
		for(int i = 1; i < n; i ++){
			split.push_back(rnd.next(1, MAXA));
		}
		sort(split.begin(), split.end());
		split.resize(distance(split.begin(), unique(split.begin(), split.end())));
		n = split.size();
		k = rnd.next(1, n);
		vector<int> v;
		for(int i = 0; i + 1 < n; i ++){
			v.push_back(split[i + 1] - split[i]);
		}
		shuffle(v.begin(), v.end());
		cout << n << " " << k << endl;
		for(auto x : v){
			cout << x << " ";
		}
		cout << endl;
	}
	if(type == "normal"){
		cout << n << " " << k << endl;
		for(int i = 1; i < n; i ++){
			cout << rnd.next(1, MAXA) << " "; 
		}
		cout << endl;
	}
}
