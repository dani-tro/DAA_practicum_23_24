#include<bits/stdc++.h>

using namespace std;

int MAXN=1e5+5;
int n,k;
vector<int> dist(MAXN);
vector<int> TVpos(MAXN);

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>k;
    dist[0]=0;
    for(int i=1;i<n;i++){
        cin>>dist[i];
        dist[i]+=dist[i-1];
    }
    int b=dist[n-1]/k;
    int br=0;
    for(int i=0;i<n;i++) {
        if(abs(b*br-dist[i])<b){
            continue;
        }
        else {
            if(abs(dist[i]-b*br)<abs(dist[i+1]-br*b)) {
                TVpos[b]=i+1;
            }
            else {
                TVpos[b]=i;
            }
            br++;
        }
    }
    int maxDist=0;
    int br2=0;
    for(int i=0;i<n;i++){
        
        for(int j=0;j<br;j++){
            if(abs(TVpos[j]*br-dist[i])>b) {
                continue;
            }
            else {
                if(abs(TVpos[j]*br-dist[i])>maxDist)maxDist=abs(TVpos[j]*br-dist[i]);   
            }
        }
    }
    cout<<maxDist;
}