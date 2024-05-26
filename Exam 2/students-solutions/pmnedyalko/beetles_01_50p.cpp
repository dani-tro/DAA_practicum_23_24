#include <bits/stdc++.h>

struct edge {
    long long first, second, w;

    bool operator<(const edge& other) {
        return w < other.w;
    }
};

const int MAX_SIZE = 1e5 + 10;
std::vector<edge> edges;
std::vector<std::pair<int,int>> pairs;
long long parent[MAX_SIZE], depth[MAX_SIZE];
long long n,m,a,b;

int find(int x) {
    if(parent[x] == -1) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

bool unionFind(int x, int y) {
    int parX = find(x);
    int parY = find(y);

    if(parX == parY) return false;

    if(depth[parX] > depth[parY]) {
        parent[parY] = parX;
    } else {
        parent[parX] = parY;
         if(depth[parX] == depth[parY])depth[parY]++;
    }

    return true;
}

long long calc(long long x, long long y, long long x1, long long y1) {
    return (x-x1)*(x-x1) + (y-y1)*(y-y1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>n;
    for (size_t i = 0; i < n; i++) {
        std::cin>>a>>b;
        pairs.push_back({a,b});
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({i+1, j+1, calc(pairs[i].first,pairs[i].second,pairs[j].first,pairs[j].second)});
        }
    }

    for (size_t i = 1; i <= n; i++) {
        parent[i] = -1;
    }

    std::sort(edges.begin(), edges.end());

    long long total = 0;
    for(edge ed : edges) {
        if(unionFind(ed.first,ed.second)) {
            total+=ed.w;
        }
    }

    std::cout<<total<<std::endl;
}