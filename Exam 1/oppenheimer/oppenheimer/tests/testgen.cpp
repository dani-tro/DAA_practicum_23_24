#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;


int main(int argc, char **argv){
	registerGen(argc, argv, 1);
	int n = opt<int>(1), k = opt<int>(2), maxa = opt<int>(3);
	cout << n << " " << k << endl;
	for(int i = 0; i < n; i ++){
		cout << rnd.next(1, maxa) << " ";
	}
	cout << endl;
}
