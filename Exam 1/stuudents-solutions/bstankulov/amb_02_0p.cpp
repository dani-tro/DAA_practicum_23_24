# include <bits/stdc++.h>
using namespace std;

#define MAX 100000
int n, k, dist[MAX]; 

bool reachable(int a[], int mid, int n, int k) { 
    int curr = a[0]; 
    int elements = 1; 
  
    for (int i = 1; i < n; i++) { 
        if (a[i] - curr >= mid) { 
            curr = a[i]; 
            elements++; 
            if (elements == k) 
                return true; 
        } 
    } 
    return 0; 
} 
  
int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    n--;
    for (int i = 0; i < n; ++i) {
        cin >> dist[i];
    }

    sort(dist, dist + n); 
    int result = -100000; 
    int left = 1, right = dist[n - 1]; 
  
    while (left < right) { 
        int mid = left + ((right - left) / 2); 
        if (reachable(dist, mid, n, k)) { 
            result = max(result, mid); 
            left = mid + 1; 
        } 
        else
            right = mid; 
    } 
    cout << result << endl;  
    return 0; 
}