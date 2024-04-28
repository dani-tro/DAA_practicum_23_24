#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static unsigned int N;
static unsigned int K;
static vector<unsigned int> arr;

int search_bigger_than_k(const vector<unsigned int> &arr, int l, int r, unsigned int k)
{
    unsigned int cur_index;
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] > k)
            cur_index = m;

        if (arr[m] < k)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

int main(){
    scanf("%u %u", &N, &K);
    arr.reserve(N);
    for(size_t i = 0; i < N; ++i){
        unsigned int temp;
        scanf("%u", &temp);
        arr.push_back(temp);
    }
    std::sort(arr.begin(), arr.end());

    unsigned int result = search_bigger_than_k(arr, 0, N, K) + 1;

    printf("%u", result);
    

    return 0;
}