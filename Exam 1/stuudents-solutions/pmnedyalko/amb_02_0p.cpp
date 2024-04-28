#include <bits/stdc++.h>

const int MAX_SIZE = 1e5;
long long arr[MAX_SIZE];
int n, k, mid, minDist, currDistR, currDistL;
long long total, l, r;

struct event{
    long long left, right;
};

std::vector<event> v;

int findTV(int dist) {
    int lcount = 0, rcount = 0;
    int size = v.size() - 1;
    currDistR = 0;
    currDistL = 0;

    for (size_t i = 0; i <= size; i++) {
        if(currDistR + v[i].right > dist) {
            rcount++;
            currDistR = 0;
        } else {
            currDistR += v[i].right;
        }

        if(currDistL + v[size - i].left > dist) {
            lcount++;
            currDistL = 0;
        } else {
            currDistL += v[i].left;
        }

    }
    
    return std::min(lcount, rcount);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>n>>k;
    for (size_t i = 0; i < n - 1; i++) {
        std::cin>>arr[i];
        total += arr[i];
    }

    v.push_back({INT_MAX, arr[0]});
    for (size_t i = 1; i < n - 1; i++) {
        v.push_back({arr[i-1], arr[i]});
    }
    v.push_back({arr[n-1], INT_MAX});
    
    l = 1;
    r = total;
    for (size_t i = 0; i < 100; i++) {
        mid = l + (r-l)/2;
        if(findTV(mid) > k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    std::cout<<l<<std::endl;
}