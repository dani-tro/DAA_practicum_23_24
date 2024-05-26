#include <iostream>
#include <bits/stdc++.h>
#include <vector>

short int N, M, K, Q;

void inputGraph(std::vector<std::vector<short int>> array,short int n)
{
    
    int x, y;
    short int t;
    for(std::size_t i = 0; i < n; i++)
    {
        std::cin >> x >> y >> t;
        array[x][y] = t;
        array[y][x] = t;
    }
}

void inputArr(std::vector<short int> vec, short int n)
{
    int x;
    for(std::size_t i = 0; i < n; i++){
        std::cin >> x;
        vec.push_back(x);
    }
}

bool member(std::vector<short int> array,short int n, short int x)
{
    for(std::size_t i = 0; i < n; i++)
    {
        if(array[i] == x)
        {
            return true;
        }
    }

    return false;
}

int Distance(std::vector<std::vector<short int>> array,short int n, std::vector<short int> finishP,short int k, int start){
    int result = 0;

    if(member(finishP, k, start))
    {
        return result;
    }

    for(std::size_t i = 0; i < n; i++)
    {   
        if(array[start][i] != 0)
        {
            int temp = array[start][i] + Distance(array, n, finishP, k, i);
            if(temp < result || result == 0){
                result = temp;
            }
        }
    }
    
    return result;
}

int main(){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::cin >> N >> M;
    std::vector<std::vector<short int>> Graph(N, std::vector<short int>(N, 0));
    inputGraph(Graph, M);

    std::cin >> K;
    std::vector<short int> sights;
    inputArr(sights, K);

    std::cin >> Q;
    std::vector<short int> hotels;
    inputArr(hotels, Q);

    for(std::size_t i = 0; i < Q; i++){
        std::cout << Distance(Graph, N, sights, K, hotels[i]) << '\n';
    }
}