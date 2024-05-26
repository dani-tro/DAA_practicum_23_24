#include <iostream>
#include <vector>

using namespace std;
short int N, M, K, Q;

void inputGraph(vector<vector<short int>> array,short int n)
{
    
    int x, y;
    short int t;
    for(size_t i = 0; i < n; i++)
    {
        cin >> x >> y >> t;
        array[x][y] = t;
        array[y][x] = t;
    }
}

void inputArr(vector<short int> vec, short int n)
{
    int x;
    for(size_t i = 0; i < n; i++){
        cin >> x;
        vec.push_back(x);
    }
}

bool member(vector<short int> array,short int n, short int x)
{
    for(size_t i = 0; i < n; i++)
    {
        if(array[i] == x)
        {
            return true;
        }
    }

    

    return false;
}

int Distance(vector<vector<short int>> array,short int n, vector<short int> finishP,short int k, int start){
    int result = 0;

    if(member(finishP, k, start))
    {
        return result;
    }

    for(size_t i = 0; i < n; i++)
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
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N >> M;
    vector<vector<short int>> Graph(N, vector<short int>(N, 0));
    inputGraph(Graph, M);

    cin >> K;
    vector<short int> sights;
    inputArr(sights, K);

    cin >> Q;
    vector<short int> hotels;
    inputArr(hotels, Q);

    for(size_t i = 0; i < Q; i++){
        cout << Distance(Graph, N, sights, K, hotels[i]) << '\n';
    }
}