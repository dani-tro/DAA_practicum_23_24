#include <bits/stdc++.h>

using namespace std;

#define MAX 100100

long long distances[MAX];
int n, k;
long long lefts, rights, middle, last_stop_value, last_stop, next_stop, used;

bool possible(long long x){
    long long wanted = x, sum = 0;
    last_stop_value=0;
    last_stop=0;
    next_stop=1;
    used = 0;
    while(next_stop < n && used < k){
        sum = 0;
        while(sum<=wanted && next_stop < n){
            sum+=distances[next_stop];
            next_stop++;
            //cout << rights << " " << middle << " " << lefts << "  at " << next_stop << endl;
        }
        if(next_stop == last_stop+1 && next_stop<n){
            next_stop++;
        }
        last_stop_value = distances[next_stop-1];
        last_stop = next_stop-1;
        used++;
        if(wanted == x){
            wanted = 2*x;
        }
    }
    if(next_stop==n)
        return true;
    return false;
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