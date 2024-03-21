#include<bits/stdc++.h>
using namespace std;


int main(){
	string t; cin >> t;
	int best_len = 0;
	char best_char = 0;
	for(int i = 0; i < t.size(); ){
		int ptr = i;
		while(ptr < t.size() && t[ptr] == t[i]){
			++ ptr;
		}
		int len = ptr - i;
		if(len > best_len || (len == best_len && t[i] > best_char)){
			best_len = len;
			best_char = t[i];
		}
		i = ptr;
	}
	cout << best_len << " " << best_char << endl;
}