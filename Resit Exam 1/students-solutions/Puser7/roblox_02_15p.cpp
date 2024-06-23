#include <bits/stdc++.h>
#define MAXN 100000000
using namespace std;

int n, k;
int nums[MAXN];

int main() {

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long ways = 0;
    for(int i = n - 1; i > 0; i--) {
        long long sum = nums[i];
        long long total = 0;
        for(int j = i - 1; j >= 0; j--) {
            total += nums[j] * sum;
            sum += nums[j];
            if(total >= k) {
                // cout << i << "   " << j << "  " << total << endl;
                ways += j + 1;
                break;
            }
        }
    }

    cout << ways;

    return 0;
}