#include<bits/stdc++.h>
using namespace std;

int n;
double m;

struct A{
    unsigned key;
    double kolich, cena;
    double taken=0;
};

A arr[100];

bool cmp (A x, A y){
    if (x.cena == y.cena) return x.kolich > y.kolich;
    return x.cena > y.cena;
}

bool cmp2 (A x, A y){
    return x.key < y.key;
}

double res=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>m>>n;

    for(int i=0;i<n;++i){
        cin>>arr[i].kolich;
        cin>>arr[i].cena;
        arr[i].taken = 0;
        arr[i].key = i;
    }

    sort(arr, arr + n, cmp);

    for(int i=0;i<n;++i)
    {
        if(m <= 0) break;

        if(m >= arr[i].kolich)
        {
            res += (arr[i].kolich*arr[i].cena);
            arr[i].taken = arr[i].kolich;
            m -= arr[i].kolich;
        }
        else{
            res += (m * arr[i].cena);
            arr[i].taken = m;
            m = 0;
        }
    }

    sort(arr, arr + n, cmp2);


    cout << fixed << setprecision(2) << res << endl;
    for(int i=0;i<n;++i){
        cout << fixed << setprecision(3) << arr[i].taken << endl;

    }

    return 0;
}