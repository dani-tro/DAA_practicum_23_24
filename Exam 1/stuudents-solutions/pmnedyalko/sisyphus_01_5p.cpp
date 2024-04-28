#include <bits/stdc++.h>

const int MAX_SIZE = 1e5;
int n, m;
long long arr[MAX_SIZE];
long long k;
long long total;

struct event {
    long long x, count;

    bool operator<(const event& other) {
        if(count == other.count) return x > other.x;
        return count < other.count;
    }
};

std::vector<event> v;

void update(int l, int r) {
    for (size_t i = l; i <= r; i++) {
        v[i].count--;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>n>>m>>k;
    v.push_back({INT_MIN, INT_MAX});
    for (int i = 0; i < n; i++) {
        std::cin>>arr[i];

        v.push_back({arr[i], 0});
    }

    int l, r;
    for (size_t i = 0; i < m; i++) {
        std::cin>>l>>r;
        update(l,r);
    }
    
    std::sort(v.begin(), v.end());

    for (size_t i = 0; i < v.size() - 1; i++) {
         if(v[i].x - k >= 0) {
             std::cout<<v[i].x<<std::endl;
             v[i].x -= k;
             std::cout<<v[i].x<<std::endl;
             k = 0;
             break;
         } else {
             k -= v[i].x;
             v[i].x = 0;
         }
    }

    for (size_t i = 0; i < v.size() - 1; i++) {
        total += v[i].x * (-1* v[i].count);
    }

    std::cout<<total<<std::endl;
}