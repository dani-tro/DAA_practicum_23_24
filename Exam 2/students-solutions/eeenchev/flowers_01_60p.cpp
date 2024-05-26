#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
#include<algorithm>
int k, n, i, j, l, maximum, counter, current_node;

std::vector<int> graph[20002];
std::queue<int> q;
std::vector<int> result;
int degree[20002];
int current_line[101];
bool seen[20002];
int main(){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    for(i = 0; i < 20001; i++){
        seen[i] = false;
    }
    for(i = 0; i < n; i++){
        std::cin >> k;
        for(l = 0; l < k; l++){
            std::cin >> current_line[l];
            seen[current_line[l]] = true;
            for(j = 0; j < l; j++){
                graph[current_line[j]].push_back(current_line[l]);
            }
        }
    }
    //std::cout << "ha" << std::endl;
    for(i = 20000; i >= 1; i--){
        if(seen[i]){
            //std::cout << i << std::endl;
            maximum = i;
            counter = 1;
            degree[maximum] = 0;
            i = 0;
        }
    }
    //std::cout << maximum << std::endl;
    for(i = maximum - 1; i >= 1; i--){
        if(seen[i]){
            counter++;
            degree[i] = 0;
        }
    }
    //std::cout << counter << std::endl;
    for(i = 1; i <= maximum; i++){
        if(seen[i]){
            //std::cout << i << std::endl;
            for(auto x : graph[i]){
                degree[x]++;
            }
        }
    }
    for(i = 1; i <= maximum; i++){
        if(seen[i] && degree[i] == 0){
            q.push(i);
            //std::cout << i;
        }
    }

    while(!q.empty()){
        current_node = q.front();
        q.pop();
        result.push_back(current_node);
        //std::cout << current_node << std::endl;
        for(auto x : graph[current_node]){
            degree[x]--;
            if(degree[x] == 0){
                q.push(x);
            }
        }
    }
    if(result.size() == counter){
        std::cout << 1;
    }else{
        std::cout << 0;
    }
    return 0;
}