#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
#include<algorithm>
const long long INF = 10e17;

struct Edge{
    int from;
    int to;
    long long weight;
    bool operator<(const Edge& other){
        if(this->weight < other.weight){
            return true;
        }
        return false;
    }
};
int parent[100001];
int rank[100001];
int edges_to_place, step = 0, set_a, set_b, another, i, j;
int find(int a){
    while(a != parent[a]){
        a = parent[a];
    }
    return a;
}

void merge(int a, int b){
    if(rank[a] > rank[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
    if(rank[a] == rank[b]){
        rank[a]++;
    }
}
long long n, x[100001], y[100001], sum = 0, temp;
Edge edges[500001];
int main(){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    for(i = 0; i < n; i++){
        parent[i] = i;
    }
    edges_to_place = n - 1;
    for(i = 0; i < n; i++){
        std::cin >> x[i] >> y[i];
        for(j = 0; j < i; j++){
            edges[step] = {i, j, (x[i] - x[j])* (x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])};
            step++;
        }
    }
    std::sort(edges, edges + ((n + 1)* n) / 2);
    step = 0;
    while(edges_to_place){
        set_a = find(edges[step].from);
        set_b = find(edges[step].to);
        if(set_a != set_b){
            sum += edges[step].weight;
            edges_to_place--;
            merge(set_a, set_b);
        }
        step++;
    }
    
    std::cout << sum;
    return 0;
}