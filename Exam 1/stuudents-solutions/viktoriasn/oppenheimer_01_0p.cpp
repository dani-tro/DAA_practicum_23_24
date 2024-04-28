#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 100000

long long n;
long long k;
long long a[MAXN];
long long s[MAXN];

int main(){
//	ios::sync_with_stdio(false);

	cin>>n>>k;
	long long curr;
	for(long long i =0; i<n; i++){
		cin>>curr;
		a[i] = curr;
		s[i] = curr;
	}
	
	sort(s, s+n);


	long long j1;
	long long j2;
	long long maxLen = 0;
	long long currL;
	long long currR;
	for(long long j1 = 0; j1<=n; j1++){		
		for(long long j2 = n-1; j2>=0; j2--){
			if(s[j2] - s[j1] <= k){
				if(maxLen < j2 -j1){
					maxLen = j2 - j1;
					currL = j1;
					currR = j2;
				}
			}
		}
	}

	
	long long currP;
	
	for(long long j =0; j<n; j++){
		
		for(long long m = currL; m<=currR; m++){
			if(a[j] == s[m] && currP != j){
			currP =j;
			cout<<j+1<<" ";
			 
			}
		}
	}
	cout<<endl;
	
}