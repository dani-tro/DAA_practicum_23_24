#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct edge{
    int from, to;
    long long distance;
    bool operator<(const edge& other) const{
        return distance < other.distance;
    }
};

int n, x, y;
vector<pair<long long, long long>> vertices;
vector<edge> edges;
int p[MAXN];
int r[MAXN];

int find(int v){
    if(p[v] == 0) return v;
    return p[v] = find(p[v]);
}

void uni(int u, int v){
    int a = find(u);
    int b = find(v);

    if(a == b) return;
    if(r[a] > r[b]) {
        p[b] = a;
    } else {
        p[a] = b;
        if(r[a] == r[b]) r[b]++;
    }
}


int main(){

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        vertices.push_back({x, y});
    }

    for(int i = 1; i <= vertices.size(); i++) {
        for(int j = i + 1; j <= vertices.size(); j++) { 
            edges.push_back({i, j, 
                (vertices[i-1].first - vertices[j-1].first) * (vertices[i-1].first - vertices[j-1].first) + 
                (vertices[i-1].second - vertices[j-1].second) * (vertices[i-1].second - vertices[j-1].second)});
        }
    }

    sort(edges.begin(), edges.end());
    long long sum = 0;
    for(edge e : edges) {
        if(find(e.from) != find(e.to)) {
            uni(e.from, e.to);
            sum += e.distance;
        }
    }

    cout << sum;

    return 0;
}