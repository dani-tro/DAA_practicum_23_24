#include <iostream>
#include <vector>

using namespace std;
int N, M, K, Q;

void inputGraph(vector<vector<short int>> array, int n)
{
    
    int x, y;
    short int t;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> t;
        array[x][y] = t;
        array[y][x] = t;
    }
}

void inputArr(int *array, int n)
{
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
}

bool member(int *array,int n, int x)
{
    int i = 0;
    while(i != n)
    {
        if(array[i] == x)
        {
            return true;
        }
        ++i;
    }

    return false;
}

int Distance(vector<vector<short int>> array, int n, int *finishP, int k, int start){
    int result = 0;

    if(member(finishP, k, start))
    {
        return result;
    }

    for(int i = 0; i < n; i++)
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

    cin >> N >> M;
    
    vector<vector<short int>> Graph;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Graph[i][j] = 0;
        } 
    }
    
    inputGraph(Graph, M);

    cin >> K;
    int *sights = new int [K];
    inputArr(sights, K);

    cin >> Q;
    int *hotels = new int [Q];
    inputArr(hotels, Q);

    for(int i = 0; i < Q; i++){
        cout << Distance(Graph, N, sights, K, hotels[i]) << '\n';
    }
}