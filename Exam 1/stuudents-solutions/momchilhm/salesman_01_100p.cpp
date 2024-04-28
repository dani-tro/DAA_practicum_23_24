#include <bits/stdc++.h>

using namespace std;

#define MAX 110

double limit;
int size;

struct item{
    double amount, price;
    int index;
    bool operator<(item& other){
        return price>other.price || (price==other.price && amount > other.amount);
    }
};

item arr[MAX];
item answer[MAX];

void solve(){
    cin >> limit >> size;
    
    for(int i = 1; i <= size; i++){
        cin >> arr[i].amount >> arr[i].price;
        arr[i].index=i;
    }

    sort(arr+1, arr+size+1);
    int count = 1;
    double res=0;
    while(count <= size && limit > 0){
        double sub = min(arr[count].amount,limit);
        limit -= sub;
        res+=sub*arr[count].price;
        answer[arr[count].index]={sub,arr[count].price,0};
        count++;
    }
    while(count <= size){
        answer[arr[count].index]={0,arr[count].price,0};
        count++;
    }
    cout << fixed << setprecision(2) << res << endl;

    for(int i = 1; i <= size; i++){
        cout << fixed << setprecision(3) << answer[i].amount << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
