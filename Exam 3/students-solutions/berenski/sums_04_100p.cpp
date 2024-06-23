#include<bits/stdc++.h>

using namespace std;

#define MAXN 105

int arr[MAXN];
int counter;
int a,b,n;
bool ans[MAXN][MAXN];
int mm;

void gen(){

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=b;j++)ans[j][i]=ans[j][i-1];
        ans[arr[i]][i]=true;    
        for(int j=1;j<=b;j++)
        {
            if(ans[j][i-1] && arr[i]+j<=b)ans[arr[i]+j][i]=true;
        }
    }

    for(int i=a;i<=b;i++)counter+=ans[i][n];


    cout<<counter;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        mm = mm>arr[i] ? mm : arr[i];
    }

    gen();
    
}