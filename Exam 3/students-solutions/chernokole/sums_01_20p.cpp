#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;

const int MAX=105;
int Arr [MAX];
bool found[MAX];
pair <int, vector<int>> St [MAX];

int N, A, B, inp, cntr=0; 


int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    cin>>N;
    cin>>A;
    cin>>B;

    for(int i=0; i<N; i++){
        cin>>inp;
        Arr[i]=inp;
    }

    St[0].second.push_back(0);
    St[0].second.push_back(Arr[0]);
    if(A<=Arr[0]&&Arr[0]<=B){
        St[0].first=1;
        found[Arr[0]]=true;
    }
    else St[0].first=0;
    
    for(int i=1; i<N; i++){
        cntr=0;
        for(auto p: St[i-1].second){
            inp=p+Arr[i];
            St[i].second.push_back(p);
            St[i].second.push_back(inp);
            if(inp<=B&&inp>=A&&!found[inp]) {
                cntr++;
                found[inp]=true;

            }
        }
        St[i].first=St[i-1].first+cntr;

    }

    cout<<St[N-1].first;




    return 0;
}