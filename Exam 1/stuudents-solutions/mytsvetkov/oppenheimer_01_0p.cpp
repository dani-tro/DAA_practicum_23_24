#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n, k, arr[MAXN];

int main(){

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int i = 0;
    int j = n - 1;
    int max = 0;

    while(i < j) {
        if(arr[j] - arr[i] <= k) 
            if(max < (j - i + 1)) max = j - i + 1;
        
        if(arr[i + 1] == arr[i]) { 
            do{
                i++;
            } while(arr[i] != arr[i - 1]);
        } else if(arr[i + 1] == arr[i]){ 
            do{
                j--;
            } while(arr[j] != arr[j + 1]);
        } else {
            i++;
        }
    }


    cout << max;

    return 0;
}