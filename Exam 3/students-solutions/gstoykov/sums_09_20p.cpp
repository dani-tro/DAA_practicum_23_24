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
    }
    int i = 1;
    //sort(arr,arr+n+1);
    while (i <=n) {
        int j = i;
        int sum = 0;
        while ( j <=n) {
            if (sum + arr[j] > b) {
                j++;
                continue;
            }
                
            sum += arr[j];
            if (sum >= a) {
                s.insert(sum);
            }
            j++;
        }
        i++;
    }
    cout << s.size();
    
}
