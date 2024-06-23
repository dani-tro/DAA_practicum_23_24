#include <bits/stdc++.h>

#define MAX 100

using namespace std;


int n, a, b;
set<int> results;
vector<int> sums;
vector<int> incomplete;
int seq[MAX];

void solve(int a, int b) {
    int current = 0;
    for (int i = 0; i < n; i++) {
        if (seq[i] > b) continue;
        if (seq[i] >= a) {
            sums.push_back(seq[i]);
            results.emplace(seq[i]);
        }
        else if (seq[i] < a) {
            incomplete.push_back(seq[i]);
        }
        for (int j = 0; j < sums.size(); j++) {
            int result = sums[j] + seq[i];
            if (result <= b) {
                sums.push_back(result);
                results.emplace(result);
            }
        }
        for (int j = 0; j < incomplete.size(); j++) {
            int result = incomplete[j] + seq[i];
            if (result >= a && result <= b) {
                sums.push_back(result);
                results.emplace(result);
            }
        }
    }
}

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    solve(a, b);
    cout << results.size();
    return 0;
}