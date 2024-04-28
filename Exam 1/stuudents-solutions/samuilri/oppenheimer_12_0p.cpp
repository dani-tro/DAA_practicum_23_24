//#include <bits/stdc++.h>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long

void sort_m(ll* arr, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i] < arr[j])
                swap(arr[i], arr[j]);
        }
    }
}


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
    bool back = true;
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
        }
        //cout << max;
    }
    cout << max;

}