#include <bits/stdc++.h>

using namespace std;

#define MAX 100100

long long distances[MAX];
int n, k;
long long lefts, rights, middle, last_stop_value, last_stop, next_stop;

bool possible(long long x){
    last_stop_value=0;
    last_stop=0;
    next_stop=1;
    while(next_stop < n){
        while(distances[next_stop]-last_stop_value<=x && next_stop < n){
            next_stop++;
        }
        if(next_stop == last_stop+1){
            return false;
        }
        last_stop_value = distances[next_stop-1];
        last_stop = next_stop-1;
    }
    return true;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i<n;i++){
        cin >> distances[i];
        
    }

    lefts = 0, rights = 100000000000000;
    while(lefts <=rights){
        middle = (rights+lefts)/2;
        if(possible(middle)){
            rights = middle - 1;
        }else{
            lefts = middle + 1;
        }
    }

    cout << lefts << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
