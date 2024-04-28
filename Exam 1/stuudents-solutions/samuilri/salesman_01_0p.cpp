#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;
#define ll long long

//ll search(vector<ll>& vec, ll beg, ll end) {
//	ll mid =beg;
//	while (true) {
//		if (vec[mid] > vec[end] - vec[mid]) {
//			return mid;
//		}
//		mid++;
//
//	}
//}
//
//int main() {
//	ll N, K;
//	cin >> N >> K;
//	vector<ll> dist;
//	vector<bool> flor;
//	ll temp;
//	for (int i = 0; i < N - 1; i++) {
//		cin >> temp;
//		dist.push_back(temp);
//		if(i>0){
//			dist[i] += dist[i - 1];
//			flor.push_back(0);
//		}
//
//	}
//	cout<<search(dist, 0, N - 2);
//
//
//}

int main() {
	vector<pair<double, double>> vec;
	vector<pair<double, double>> vec2;
	vector<pair<double, double>> toPrint;
	int m, n;
	cin >> m >> n;
	double tempA = 0;
	double tempB = 0;

	for (int i = 0; i < n; i++) {
		cin >> tempA >> tempB;
		vec.push_back({ tempB,tempA }); //price, weight
		vec2.push_back({ tempA,tempB });//weight, price
		//cout << "done";
	}

	sort(vec.begin(), vec.end());
	double currInBag = 0;
	double sum = 0;
	for (int i = n-1; i >=0 ; i--) {
		if (currInBag + vec[i].second > m) {
			double M = double(m) - currInBag;
			sum += M * vec[i].first;
			toPrint.push_back({ vec[i].first,M });
			break;
		}
		else {
			currInBag += vec[i].second;
			sum += vec[i].first * vec[i].second;
			toPrint.push_back(vec[i]);
		}
	}
	cout << fixed << setprecision(2) <<  sum << endl;
	double epsilon = 0.00004;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (toPrint[j].first - epsilon <vec2[i].second && toPrint[j].first + epsilon > vec2[i].second) {
				cout << fixed << setprecision(3) <<toPrint[j].second << endl;
				break;
			}
		}
	}

}