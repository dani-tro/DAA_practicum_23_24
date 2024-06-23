#include <cmath>
#include <climits>
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int const MAXN = 100001;
int const MAXK = 1001;



int line[MAXN];
int lineK[MAXK];

int calc(int beg, int end, int K, int N) {
    if (beg >= end) return -1;
    int maxim;
    for (int i = 0; i <= K; i++) {
        maxim = max(line[beg] + calc(beg + line[i], end, K, N), line[end] + calc(beg, end - line[i], K, N));
    }
    return maxim;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> line[i];
    }
    lineK[0] = 0;
    for (int i = 1; i <= K; i++) {
        cin >> lineK[i];
    }
    int maxSum = calc(0, N - 1, K, N);
    cout << maxSum;
}
