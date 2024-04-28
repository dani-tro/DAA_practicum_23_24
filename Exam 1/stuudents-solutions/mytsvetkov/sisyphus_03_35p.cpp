#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n, m, arr[MAXN];
long long k;
long long endsFr[MAXN];
//prefixSums[0] = 0;
long long prefixSums[MAXN];

int main(){

    cin >> n >> m >> k;

    long long currSum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        currSum += arr[i];
        prefixSums[i + 1] = currSum;
    }

    long long totalHardness = 0;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        totalHardness += prefixSums[b] - prefixSums[a - 1];

        if(a == b) {
            endsFr[a-1]++;
            continue;
        }

        endsFr[a-1]++;
        endsFr[b-1]++;
    }

    //<frequency, original_Index>
    vector<pair<long long, int>> pairs;
    for(int i = 0; i < n; i++) {
        pairs.push_back({endsFr[i], i});
        // cout << endsFr[i] << "   " << i << endl;
    }

    sort(pairs.begin(), pairs.end());

    for(int i = n - 1; i >= 0 && k > 0; i--) {
        totalHardness -= pairs[i].first * min((long long) arr[pairs[i].second], k);
        // cout << "sub " << pairs[i].first * min((long long) arr[pairs[i].second], k) << "  " << 
        //                 pairs[i].first << " " << pairs[i].second << endl;
        k -= min((long long) arr[pairs[i].second], k);
    }

    cout << totalHardness;

    return 0;
}