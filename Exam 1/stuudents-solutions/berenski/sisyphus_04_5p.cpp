#include<bits/stdc++.h>

using namespace std;
const int MAXN=1e6+5;

int n,m;
long long k;
    long long sum=0;
vector<pair<int,int>> TravCount_A(MAXN);
vector<pair<int,int>> d(MAXN);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        cin>>TravCount_A[i].second;
        TravCount_A[i].first=0;
    }

    for(int i=0;i<m;i++){
        cin>>d[i].first>>d[i].second;
        d[i].first--;
        d[i].second--;
        for(int j=d[i].first;j<=d[i].second;j++){
            TravCount_A[j].first++;
        }
    }

    sort(TravCount_A.begin(),TravCount_A.begin()+n);

    for(int i=n-1;i>=0&&TravCount_A[i].first;i--){
        
        if(k>=TravCount_A[i].second){
            k=k-TravCount_A[i].second;
            TravCount_A[i].second=0;
        }
        else{
            TravCount_A[i].second=TravCount_A[i].second-k;
            k=0;
            break;
        }
         sum+=(TravCount_A[i].first*TravCount_A[i].second);
    }

    cout<<sum;

}