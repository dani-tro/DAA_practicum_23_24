#include <bits/stdc++.h>
using namespace std;

vector<long long> distances;

vector<pair<long long,bool>> distancesbrute;

int main(){
    //=
    //+
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,k;
    cin >> n>> k;
    for(long long i=0;i<n-1;i++){
        long long distance;
        cin >> distance;
        distances.push_back(distance);
    }
    for(long long i=0;i<n-1;i++){
        for(long long j=0;j<n;j++){
            distancesbrute.push_back({distances[i]+distances[j],false});
        }
    }
    sort(distancesbrute.begin(),distancesbrute.end());
    long long i=0;
    while(k>0 && i <n-1){
            if(distancesbrute[i].second == false){
                distancesbrute[i].second = true;
                k--;
            }
            i++;
        }
    cout << distancesbrute[i-1].first;
    return 0; 
}