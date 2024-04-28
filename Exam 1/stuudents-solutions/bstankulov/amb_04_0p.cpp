# include <bits/stdc++.h>
using namespace std;

#define MAX 100000
int cc, n, k, pos[MAX]; 

bool isValid(int mid) { 
    int currDist = 0; 
    int placedTVs = 0;
    for (int i = 1; i < n; i++) {
        currDist += pos[i] - pos[i-1];
        if (currDist > mid) {
            placedTVs++;
            currDist = pos[i] - pos[i-1];
        }
    } 
    return placedTVs <= k; 
} 
  
int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    pos[0] = 0;
    for (int i = 1; i < n; ++i) {
        cin >> cc;
        pos[i] = cc + pos[i - 1];
    }

    int left = 1, right = pos[n - 1]; 
    int mid = (left+right)/2;
    int currBest = mid;
    while (left <= right) { 
        mid = (left+right)/2;
        if (isValid(mid)) { 
            currBest = mid;
            right = mid - 1; 
        } 
        else
            left = mid + 1; 
    } 
    cout << currBest;  
    return 0; 
}