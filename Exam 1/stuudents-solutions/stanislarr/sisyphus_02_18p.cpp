#include <iostream>
#include <algorithm>

using namespace std;
long long n, m, k;

long long arr[100000];
pair<long, long> dists[1000000];

int getSum(long start, long end) {
    long long sum = 0;
    for (long i = start; i < end; i++) {
        sum += arr[i];
    }

    return sum;
}

void printArr(long long n) {
    for (long long i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main() {
    cin >> n >> m >> k;

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (long long i = 0; i < m; i++) {
        long l, r;

        cin >> l >> r;
        dists[i] = pair<long, long>(l - 1, r - 1);
    }

    while (k > 0) {
        bool didChange = false;
        for (long long i = 0; i < m; i++) {
            for (long j = dists[i].second; j >= dists[i].first; j--) {
                if (arr[j] > 0) {
                    didChange = true;
                    arr[j]--;
                    k--;
                    break;
                }
            }
        }
        if (didChange) {
            didChange = false;
        }
        else {
            k = 0;
        }
    }

    long long totalSum = 0;

    for (long long i = 0; i < m; i++) {
        totalSum += getSum(dists[i].first, dists[i].second + 1);
    }

    cout << totalSum << endl;


}