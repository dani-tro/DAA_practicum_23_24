#include "testlib.h"
#include<bits/stdc++.h>
#define pb push_back
#define all(A) A.begin(), A.end()
using namespace std;

template<class T> using matrix = vector<vector<T>>;

int main(int argc, char **argv){
	registerGen(argc, argv, 1);
	int n = opt<int>(1);
	int k = opt<int>(2);
	int seed = opt<int>(3);
	int ans = opt<int>(4);
	vector<int> out(n);
	if(ans == 2){
		iota(all(out), 1);
		reverse(all(out));
	}
	else if(ans == 1){
		iota(all(out), 1);
		shuffle(all(out));
	}
	else if(ans == 0){
		matrix<int> vs(k);
		for(int i = 1; i <= n; i ++){
			vs[i % k].pb(i);
		}
		for(int i = 0; i < k; i ++){
			shuffle(all(vs[i]));
		}
		for(int i = 1; i <= n; i ++){
			out[i - 1] = vs[i % k].back();
			vs[i % k].pop_back();
		}
	}
	cout << n << " " << k << endl;
	for(auto x : out){
		cout << x << " ";
	}
	cout << endl;
}
/**

*/
