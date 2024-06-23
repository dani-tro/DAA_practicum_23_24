#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n, a, b;
int nums[MAXN];
long long cnt = 0;
bool sums[MAXN];

void calc(int currSum, int ind) {
    if(currSum > b) return;
    if(currSum >= a && currSum <= b) sums[currSum] = true;
    if(ind >= n) return;

    for(int i = ind + 1; i < n; i++) {
        calc(currSum + nums[i], i);
    }
}


int main() {

    cin >> n >> a >> b;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    calc(0, -1);
    int tot = 0;
    for(int i = a; i <= b; i++) {
        if(sums[i]) tot++;
    }

    cout << tot;

    return 0;
}