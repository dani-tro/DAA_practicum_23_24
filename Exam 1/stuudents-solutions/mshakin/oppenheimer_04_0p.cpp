#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static unsigned int N;
static unsigned int K;
static vector<unsigned int> v;


int main(){
    scanf("%u %u", &N, &K);
    v.reserve(N);
    for(size_t i = 0; i < N; ++i){
        unsigned int temp;
        scanf("%u", &temp);
        v.push_back(temp);
    }
    std::sort(v.begin(), v.end());

    unsigned int result;
    int l = 0;
    int r = N - 1;
    while(l<r){
            if((v[r] - v[l]) > K) r-=1;
            else if((v[r] - v[l]) < K) l+=1;
            else if(K == (v[r] - v[l]))break;
        }
        result = r - l + 1;

    printf("%u", result);
    

    return 0;
}