#include <bits/stdc++.h>

const int MAX_SIZE = 1e5;
long long arr[MAX_SIZE];
int n, k, mid, minDist, lastTVR, lastTVL, lastR, lastL;
long long total, l, r;

struct event{
    long long left, right;
};

std::vector<event> v;

int findTV(int dist) {
    int lcount = 0, rcount = 0;
    int size = v.size() - 1;
    lastTVR = INT_MAX;
    lastTVL = INT_MAX;

    for (size_t i = 0; i < size; i++) {

        if(lastTVR >= dist && v[i].right >= dist) {
            rcount++;
            lastTVR = v[i].right;
            lastR = i;
        }else if(lastTVR + v[i].right > dist) {
            rcount++;
            lastTVR = v[i].right;
            lastR = i;
        }else {

            if(lastTVR == INT_MAX) {
                lastTVR = 0;
            }

            lastTVR += v[i].right;
        }

        if(lastTVL >= dist && v[size - i].left >= dist) {
            lcount++;
            lastTVL = v[size - i].left;
            lastR = size - i;
        }else if(lastTVL + v[size - i].left > dist) {
            lcount++;
            lastTVR = v[size - i].left;
            lastR = size - i;
        }else {

            if(lastTVL == INT_MAX) {
                lastTVL = 0;
            }

            lastTVL += v[size - i].left;
        }
    }

    if(lastTVL > dist && lastL != 0) {
        lcount++;
    }

    if(lastTVR > dist && lastR != size) {
        rcount++;
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
    v.push_back({arr[n-2], INT_MAX});
    

    l = 1;
    r = total;
    for (size_t i = 0; i < 10; i++) {
        mid = l + (r-l)/2;
        if(findTV(mid) > k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    std::cout<<l<<std::endl;
}