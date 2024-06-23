#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

bool suma(int nums[100], int target, int i,int n){
    if(target == 0 ) return true;
    if(i >= n) return false;
    if(target-nums[i] < 0){
        return(suma(nums,target,i+1,n));
    }else{
        return(suma(nums,(target-nums[i]),i+1,n) or suma(nums,target,i+1,n));
    }
}

int num[101];

int sums = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a,b;
    cin >> n >> a >> b;
    if(a > b){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n;i++){
        cin>>num[i];
    }
    num[n] = num[n-1];
    for(int j = a;j <= b;j++){
        if(suma(num,j,0,n)){
            ++sums;
        }
    }

    cout << sums;
    return 0;
}
