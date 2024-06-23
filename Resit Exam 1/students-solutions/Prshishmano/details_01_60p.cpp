#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool shegobude(int dni, const vector<pair<int, int>>& zavod, int p) {
    vector<long long> imame;
    for (int i = 0; i < zavod.size(); i++) {
        long long mndni = dni - zavod[i].second;
        if (mndni > 0) {
            long long chasti = mndni / zavod[i].first;
            imame.push_back(chasti);
        }
    }
    
    sort(imame.begin(), imame.end(), greater<long long>());
    
    long long vschasti = 0;
    for (int i = 0; i < zavod.size(); i++) {
        vschasti += imame[i];
        if (vschasti >= p) {
            return true;
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, p;
    cin >> n >> p;
    
    vector<pair<int, int>> zavodi(n);
    for (int i = 0; i < n; i++) {
        cin >> zavodi[i].first >> zavodi[i].second;
    }
    
    int start = 0, stop = 1000000;
    int malko = stop;
    
    while (start <= stop) {
        int mid = start + (stop - start) / 2;
        
        if (shegobude(mid, zavodi, p)) {
            malko = mid;
            stop = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    cout << malko;
    
    return 0;
}
