#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
#include<algorithm>
const long long INF = 10e17;
struct Node{
    short index;
    long long x_1;
    long long y_1;
    bool operator<(const Node& other){
        if(this->x_1 < other.x_1 || (this->x_1 == other.x_1 && this->y_1 < other.y_1)){
            return true;
        }
        return false;
    }
};

int parent[100001];
int rank[100001];
int edges_to_place, step, set_a, set_b, another;
std::pair<int, long long> current_minimum;
int find(int a){
    if(a != parent[a]){
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
long long n, x, y, sum = 0, temp;
Node beetles[100001];
short i;
long long calc(long long a, long long b){
    return (beetles[a].x_1 - beetles[b].x_1) * (beetles[a].x_1 - beetles[b].x_1) + (beetles[a].y_1 - beetles[b].y_1) * (beetles[a].y_1 - beetles[b].y_1);
}
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
        std::cin >> x >> y;
        beetles[i] = {i, x, y};
    }
    std::sort(beetles, beetles + n);
    // std::cout <<std::endl;
    // for(i = 0; i < n; i++){
    //     std::cout << beetles[i].x_1 << ' ' << beetles[i].y_1 << std::endl;
    // }
    step = 0;
    while(edges_to_place){
        set_a = find(beetles[step].index);
        another = step + 1;
        i = beetles[step].x_1;
        current_minimum = {-1, calc(step, another)};
        while(another < n && beetles[another].x_1 - i <= 10){
            set_b = find(beetles[another].index);
            temp = calc(step, another);
            //std::cout << temp << std::endl;
            if(set_a != set_b && current_minimum.second > temp){
                current_minimum = {another, temp};
            }
            another++;
        }
        sum += current_minimum.second;
        //std::cout << current_minimum. first << ' ' << current_minimum.second << std::endl;
        merge(set_a, find(current_minimum.first));
        edges_to_place--;
        step++;
    }
    
    std::cout << sum;
    return 0;
}