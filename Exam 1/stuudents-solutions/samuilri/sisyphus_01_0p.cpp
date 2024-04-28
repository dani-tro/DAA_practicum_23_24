#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;
#define ll long long

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<pair<int, int>> vec;
	vector<pair<int, int>> dist;
	for (int i = 0; i < 5; i++) {
		vec.push_back({ i,0 });
	}
	for (int i = 0; i < N; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		if (temp2 > temp1) {
			dist.push_back({ temp1,temp2 });
		}
		else { swap(temp1, temp2); dist.push_back({ temp1,temp2 }); }
		while (temp1 < temp2) {
			vec[temp1].second++;
			temp1++;
		}
	}
	
	for (int i = 0; i < N; i++) {
		swap(vec[i].first, vec[i].second);
		
	}
	sort(vec.begin(), vec.end());
	for (int i = N - 1; i >= 0; i--) {
		while (vec[i].first >= 0 && K > 0) {
			vec[i].first = vec[i].first - 1;
			K--;
		}
	}
	for (int i = 0; i < N; i++) {
		swap(vec[i].first, vec[i].second);
		
	}
	sort(vec.begin(), vec.end());
	long long sum = 0;
	for (int i = 0; i < M; i++) {
		for (int j = dist[i].first; j <= dist[i].second; j++) {
			sum += vec[j].second;
			//cout<< vec[j].second<<endl;
			//cout << sum<<endl;
		}
	}
	
	cout << sum;
}