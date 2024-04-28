#include <bits/stdc++.h>
//#include <iostream>
#include<vector>
using namespace std;
#define ll long long

//void sort_m(ll* arr,int N) {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (arr[i] < arr[j])
//                swap(arr[i], arr[j]);
//        }
//    }
//}

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
    sort(arr);
    /*sort_m(arr, N);
    for (int i = 0; i < N; i++) {
        cout << arr[i]<<" ";
    }*/

    int start = 0;
    int end = 0;
    int max = 0;
    while (start <= N - 1) {
        if (arr[end] - arr[start] <= K) {
            if (end - start >= max)
                max = end - start+1;
            end++;
        }
        //if (end >= N)
        //    end--;
        else if (arr[end] - arr[start] > K ||end==N-1) {
            start++;
        }
        cout << max;

    }
    cout << "\n";
    cout << max;
 
    delete[] arr;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
