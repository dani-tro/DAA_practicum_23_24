#include <bits/stdc++.h>
using namespace std;

vector<long long> atoms;

int main(){
    //=
    //+
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int value;
        cin >> value;
        atoms.push_back(value);
    }
    sort(atoms.begin(),atoms.end());
    int maxans = 1;
    int curmax = 1;
    int curbeginindex = 0;
    int curdiff;
    for(int i = 1;i<n;i++){ //i 6 maxans 5 atoms[6] 8 curbegindx 3 curmax 2
        if(atoms[i] - atoms[curbeginindex] <= k){
            curmax++;
            maxans = max(maxans,curmax);
        }else{
            curmax++;
            while(atoms[i] - atoms[curbeginindex] > k){
                curbeginindex++;
                curmax--;
            }
        }
    }
    cout << maxans;
    return 0;
}