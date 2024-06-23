#include<bits/stdc++.h>

using namespace std;

#define MAXN 105

int arr[MAXN];
int counter;
int a,b,n;
bool ans[MAXN][2];

void gen(){

    for(int i=0;i<n;i++)
    {
        ans[arr[i]][i%2]=true;
        for(int j=0;j<n;j++)
        {
            if(ans[j][(i+1)%2] && arr[i]+j<n)ans[arr[i]+j][i%2]=true;
        }
    }

    for(int i=a-1;i<b;i++)counter+=ans[i][(n-1)%2];

    for(int i=0;i<n;i++)cout<<ans[i][(n-1)%2]<<" ";
    cout<<endl;
    cout<<counter;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    gen();
    
}