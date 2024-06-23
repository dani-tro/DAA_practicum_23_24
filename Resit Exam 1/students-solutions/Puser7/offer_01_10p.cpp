#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n, k;
int nums[MAXN];

int main() {

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums, nums + n);

    long long sum = 0;
    for(int i = n - 1; i >= 0; i -= 2) {
        sum += nums[i];
    }

    cout << sum;

    return 0;
}