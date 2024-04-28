//#include <bits/stdc++.h>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

//void sort_m(ll* arr, int N) {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (arr[i] < arr[j])
//                swap(arr[i], arr[j]);
//        }
//    }
//}


int main()
{


    int N;
    long long K;
    cin >> N >> K;
    //long long* arr = new long long[N];
    vector<ll> arr;
    ll p;
    for (long long i = 0; i < N; i++) {
        cin >> p;
        arr.push_back(p);
    }
    sort(arr.begin(), arr.end());
    //sort_m(arr, N);
    /*for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }*/

    ll start = 0;
    ll end = 0;
    ll max = 0;
    while (start <= N - 1) {
        if (end < N-1 && arr[end] - arr[start] <= K ) {
            if (end - start  >= max)
                max = end - start + 1;
            end++;
        }
        //if (end >= N)
        //    end--;
        else if (arr[end] - arr[start] > K || end == N - 1) {
            if (end - start  >= max)
                max = end - start + 1;
            start++; 
            if (end - start >= max)
                max = end - start + 1;
        }
        //cout << max;
    }
    cout << max;

}


//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//#define ll long long
//
//ll search(vector<ll>& vec, ll beg, ll end) {
//	ll mid = (beg + end) / 2;
//}
//
//int main() {
//	ll N, K;
//	cin >> N >> K;
//	vector<ll> dist;
//	ll temp;
//	for (int i = 0; i < N - 1; i++) {
//		cin >> temp;
//		dist.push_back(temp);
//		if(i>0)
//			dist[i] += dist[i - 1];
//
//	}
//
//
//
//}
//



