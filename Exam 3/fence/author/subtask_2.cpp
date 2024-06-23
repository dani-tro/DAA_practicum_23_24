#include<bits/stdc++.h>
using namespace std;

int s,ans;

void brute(int sum,int last,int flag){
    if(sum==0){
        ans++;
        return;
    }

    if(flag==0){
        for(int i=last+1;i<=sum;i++){
            brute(sum-i,i,1);
        }
    }else{
        for(int i=min(last-1,sum);i>=1;i--){
            brute(sum-i,i,0);
        }
    }
}

int main(){

    cin>>s;
    brute(s,0,0);
    brute(s,s,1);
    cout<<ans<<"\n";

    return 0;
}
