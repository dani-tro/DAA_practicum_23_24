#include<bits/stdc++.h>

using namespace std;
int MAXN=1e5+5;

int n,k;
vector<int> v(MAXN);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.begin()+n);
    int minId=0,maxId;
    int maxCount=0;
    for(maxId=0;maxId<n;maxId++){

        if(v[maxId]-v[minId]>k){
            minId++;
        }
        else {
            if(maxCount<maxId-minId){
                maxCount=maxId-minId;
            }
        }
    }

    for(int i=0;i<n;i++)cout<<v[i]<<" ";
    cout<<endl;
    cout<<maxCount+1;
}