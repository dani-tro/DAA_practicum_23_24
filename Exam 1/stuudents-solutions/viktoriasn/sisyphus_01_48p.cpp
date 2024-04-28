#include<iostream>
using namespace std;

#define MAXN 100000
#define MAXM 1000000

long long n, m, k;
long long a[MAXN];
pair<long long, long long> t[MAXM];


int indexOfMax(long long vec[], int len){
	int ind = 0;
	for(int i = 0; i<len; i++){
		if(vec[i] > vec[ind]){
			ind = i;
		}
	
	}
	return ind;
}



int main(){
	cin>>n>>m>>k;
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}	
	long long occurr[n];
	for(int i = 0; i<n; i++){
		occurr[i] = 0;
	}
	for(int i = 0; i<m; i++){
		cin>>t[i].first>>t[i].second;
		for(int j = t[i].first; j<=t[i].second; j++){
			occurr[j]++;
		}
	}

	while(k> 0){
		int ind = indexOfMax(occurr, n);
		while(a[ind]> 0 && k>0){
			a[ind]--;
			k--;
		}
		occurr[ind] = -1;
	}
	
	long long sum = 0;
	for(int i = 0; i<m; i++){
		for(int s = t[i].first; s<= t[i].second; s++){
			sum+= a[s-1];
		}
	}
	cout<<sum<<endl;
	return 0;
}