#include <bits/stdc++.h>
using namespace std;
const long long MAX = 102400;
long long Arr[MAX];
long long N,K;

long long curr_lenght=1;
long long curr_min_ptr=0;
long long longest=1;


int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin>>N>>K;
    for(long long i=0;i<N;i++){
        cin>>Arr[i];
    }

    sort(begin(Arr),&Arr[N]);

    for(long long i=0;i<N;i++){
        if(Arr[i]-Arr[curr_min_ptr]<=K){
            curr_lenght++;
        }
        else {
            longest=max(longest,curr_lenght);
            while(curr_min_ptr<N&&curr_min_ptr<i&&Arr[i]-Arr[curr_min_ptr]>K){
                curr_min_ptr++;
            }
            curr_lenght=i-curr_min_ptr+1;
        }
    }
    longest=max(longest,curr_lenght);

    std::cout<<longest;


}
