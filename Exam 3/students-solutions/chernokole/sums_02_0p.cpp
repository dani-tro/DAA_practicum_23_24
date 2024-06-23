#include <iostream>
#include <vector>
#include <cmath>
//#include <bits/stdc++.h>
using namespace std;

const int MAX=105;
int Arr [MAX];
bool found[MAX];
vector<int> St;
int S=0;

int N, A, B, inp, cntr=0; 


int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    std::cout.tie(NULL);

    cin>>N;
    cin>>A;
    cin>>B;

    St.push_back(0);
    for(int i=0; i<N; i++){
        cin>>inp;
        Arr[i]=inp;
      //  cout<<inp;
    
    }

    for(int i=0; i<N;i++){
        int s=pow(2,i);
        int b=0;
        while(b<s){
            int helper=St[b]+Arr[i];
            if(helper>B) continue;
            St.push_back(helper);
            //std::cout<<helper;

            if(helper>=A&&!found[helper]) {
                S++;
                found[helper]=true;
            }
            b++;
    }
    }
    

    cout<<S;




    return 0;
}