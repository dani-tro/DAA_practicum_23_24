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
long long iter;
long long sum=0;

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin>>N>>M>>K;

    for(long long i=0;i<N;i++){
        cin>>repeated_paths[i].weight;
    }

    for(long long i=0;i<M;i++){
        cin>>l>>r;
        for(long long j=l-1;j<r;j++){
            repeated_paths[j].occur++;
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
