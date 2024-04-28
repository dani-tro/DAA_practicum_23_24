#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

#define MAXN 100

int n;
double m;
double a[MAXN];
double b[MAXN];
pair<pair<double, double>, int> vec[MAXN];



 bool cmp(const pair<pair<double, double>, int> p1, const pair<pair<double, double>, int> p2){
 		return p1.first.second>p2.first.second;
 }
 
 bool cmp2(const pair<int, double> p1, const pair<int, double> p2){
 		return p1.first<p2.first;
 }

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin>>m;
	cin>>n;
	for(int i =0; i<n; i++){
		cin>>vec[i].first.first>>vec[i].first.second;
		vec[i].second = i;
	}
	
	sort(vec, vec+n, cmp);

	pair<int, double> takeVec[n];
	double wLeft = m;
	double maxWin = 0;
	int len = 0;
	
//	if(wLeft >0){
//		double take = min(vec[i].first.first, wLeft);
//		double currPrice = take*vec[i].first.second;
//		takeVec[i].first = vec[i].second;
//		takeVec[i].second = take;
//		maxWin += currPrice;
//		wLeft -= take;
//		len++;
//	} else{
//		takeVec[i].first =  vec[i].second;
//		takeVec[i].second = 0;
//	}
	for(int i = 0; i<n ; i++){
//		if(wLeft <=0){
//			break;
//		}
		double take = min(vec[i].first.first, wLeft);
		double currPrice = take*vec[i].first.second;
		takeVec[i].first = vec[i].second;
		takeVec[i].second = take;
		maxWin += currPrice;
		wLeft -= take;
		len++;
	}
	sort(takeVec, takeVec + n, cmp2);
	cout << fixed << setprecision(2)<<maxWin<<endl;
	for(int i = 0; i<n; i++){
		cout << fixed << setprecision(3)<<takeVec[i].second<<endl;
	}
	
}