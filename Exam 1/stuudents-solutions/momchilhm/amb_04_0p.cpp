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
    while(next_stop < n){
        sum = 0;
        while(sum + distances[next_stop] < wanted && next_stop < n){
            sum+=distances[next_stop];
            //cout << lefts << " " << middle << " " << rights << " at " << next_stop << " " << sum << endl;
            next_stop++;
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
    if(used > k)
        return false;
    return true;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i<n;i++){
        cin >> distances[i];
        
    }

    lefts = 0, rights = 100000000000000;
    while(lefts + 1 < rights){
        middle = (rights+lefts)/2;
        if(possible(middle)){
            rights = middle;
        }else{
            lefts = middle;
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
