#include<bits/stdc++.h>
using namespace std;

int s,ans;
int a[47];
int r[47];

bool check(int len){
    for(int i=1;i<=len-1;i++){
        r[i]=a[i+1]-a[i];
    }
    for(int i=1;i<=len-1;i++){
        if(r[i]==0)return false;
        if(i>1 and r[i]>0 and r[i-1]>0)return false;
        if(i>1 and r[i]<0 and r[i-1]<0)return false;
    }
    return true;
}

void brute(int sum,int pos){
    if(sum==0){
        if(check(pos-1))ans++;
    }else{
        for(int i=1;i<=sum;i++){
            a[pos]=i;
            brute(sum-i,pos+1);
        }
    }
}

int main(){
    
    cin>>s;
    brute(s,1);
    cout<<ans<<"\n";

    return 0;
}
