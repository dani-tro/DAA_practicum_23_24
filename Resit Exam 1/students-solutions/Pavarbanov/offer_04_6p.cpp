#include <bits/stdc++.h>

using namespace std;

int n, k;
int prices[100000];
int sum = 0;

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) count++;

    }

    int pivot_idx = start + count;
    swap(arr[pivot_idx], arr[start]);
    int i = start, j = end;

    while (i < pivot_idx && j > pivot_idx) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivot_idx && j > pivot_idx) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivot_idx;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end) return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void solve() {
    if (k > n) return;
    int del = n / k;
    int remainder = n % k;
    int index = 0;
    do {
        sum -= prices[index];
        if (index == 0) {
            index += remainder;
        } else {
            index += k;
        }
    } while (index < n);
    
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
        sum += prices[i];
    }

    quickSort(prices, 0, n - 1);
    solve();
    cout << sum;
    // for (int i = 0; i < n; i++) {
    //     cout << prices[i] << "  ";
    // }
}