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

struct interval {
    long long a, type;

    bool operator<(const interval& other) {
        if(a == other.a) return type > other.type;
        return a < other.a;
    }
};

std::vector<event> v;
std::vector<interval> in;

void update() {
    int begin = in[0].a;
    int end = in[in.size() - 1].a;
    int current = 0;
    int idx = 0;
    for (size_t i = begin; i <= end; i++) {
        
        while(idx < in.size() && in[idx].a < i) {
            idx++;
        }

        while(idx < in.size() && in[idx].a == i && in[idx].type == 1) {
            current++;
            idx++;
        }

        v[i].count = -current;

        while(idx < in.size() && in[idx].a == i && in[idx].type == -1) {
            current--;
            idx++;
        }
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
        in.push_back({l,+1});
        in.push_back({r,-1});
    }
    
    std::sort(in.begin(), in.end());
    update();
    std::sort(v.begin(), v.end());

    for (size_t i = 0; i < v.size() - 1; i++) {
         if(v[i].x - k >= 0) {
             v[i].x -= k;
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