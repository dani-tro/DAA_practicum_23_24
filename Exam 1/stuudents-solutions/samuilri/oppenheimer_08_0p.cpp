//#include <bits/stdc++.h>
#include <iostream>
#include<vector>
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
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);


    int N;
    long long K;
    cin >> N >> K;
    long long* arr = new long long[N];
    for (long long i = 0; i < N; i++) {
        cin >> arr[i];
    }
    //sort(arr);
    sort_m(arr, N);
    /*for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }*/

    int start = 0;
    int end = 0;
    int max = 0;
    bool back = true;
    while (start < N - 1) {
        if (arr[end] - arr[start] <= K && end != N) {
            if (end - start + 1 > max)
                max = end - start + 1;
            end++;
        }
        //if (end >= N)
        //    end--;
        else if (arr[end] - arr[start] > K || end == N - 1) {
            start++;
        }
        //cout << max;
        //cout << max;
    }
    cout << max;

}
