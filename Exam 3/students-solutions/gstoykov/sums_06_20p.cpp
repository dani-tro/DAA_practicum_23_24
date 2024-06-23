#include <bits/stdc++.h>
using namespace std;
const int SIZE = 105;
int arr[SIZE];
int dp [SIZE][SIZE];
int n,a,b;
set<int> s;
int main() {
    #define endl '\n'
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b;
    for (size_t i = 1; i <= n; i++) {
        int d;
        cin >> d;
        arr[i] = d;
        dp[d][d] = 1;
    }
    int i = 1;
    while (i <=100) {
        int j = i;
        int sum = 0;
        while ( j <=100) {
            if (sum + arr[j] > b)
                break;
            sum += arr[j];
            if (arr[j] >= a) {
                s.insert(sum);
            }
            j++;
        }
        i++;
    }
    cout << s.size();
    
}
