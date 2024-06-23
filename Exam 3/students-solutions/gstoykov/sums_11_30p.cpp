#include <bits/stdc++.h>
using namespace std;
const long long SIZE = 105;
long long arr[SIZE];
long long dp [SIZE][SIZE];
long long n,a,b;
set<long long> s;
long long counter = 0;
int main() {
    #define endl '\n'
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b;
    for (size_t i = 0; i < n; i++) {
        long long d;
        cin >> d;
        arr[i] = d;
    }
    
    long long i = 0;
    sort(arr,arr+n);
    while (i <n) {
        long long j = i;
        long long sum = 0;
        while ( j <n) {
            if (sum + arr[j] > b) {
                j++;
                continue;
            }
                
            sum += arr[j];
            if (sum >= a) {
                if (!s.count(sum)) {
                    s.insert(sum);
                    counter++;
                }
            }
            j++;
        }
        i++;
    }
    cout << counter;
    
}
