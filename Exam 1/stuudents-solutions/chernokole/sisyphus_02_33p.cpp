#include <bits/stdc++.h>
using namespace std;
const unsigned MAX = 1024000;
long long l,r,N,M,K;

struct Repeat{
    long long weight=0;
    long long occur=0;

    void print () const{
        cout<<weight<<" "<<occur<<endl;
    }

    bool operator<(const Repeat& other){
        if(occur==other.occur){
            return weight<other.weight;
        }
        return occur<other.occur;
    }
};

Repeat repeated_paths [MAX];
long long occurances[MAX];
long long place=0;
long long iter;
long long sum=0;

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin>>N>>M>>K;

    for(long long i=0;i<N;i++){
        cin>>repeated_paths[i].weight;
        occurances[i]=0;
    }


    for(long long i=0;i<M;i++){
        cin>>l>>r;
        occurances[l-1]++;
        occurances[r-1]--;
    }

    for(long long i=0;i<N;i++){
        if(occurances[i]==0){
            repeated_paths[i].occur=place;
        }
        else if(occurances[i]>0){
            place+=occurances[i];
            repeated_paths[i].occur=place;
        }
        else {
            repeated_paths[i].occur=place;
            place+=occurances[i];
        }
    }

    sort(begin(repeated_paths),&repeated_paths[N]);

    iter=N-1;

    while(K>0&&iter>=0){
        while(repeated_paths[iter].weight>0&&K>0){
            repeated_paths[iter].weight--;
            K--;
        }
        iter--;
    }

    for(long long i=0;i<N;i++){
        sum+=repeated_paths[i].occur*repeated_paths[i].weight;
    }


    cout<<sum;

}
