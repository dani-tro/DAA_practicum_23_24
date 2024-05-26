#include<iostream>
#define MAXS 1000
using namespace std;

int M, N, cntMax = 0, cnt = 1;
int table[MAXS][MAXS];

int checkMax(int table[MAXS][MAXS])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M-1; j++)
        {
            if(table[i][j] != table[i][j+1])
            {
                cnt++;
            }
            cntMax += cnt;
        }
        cnt = 1;
    }
    return cntMax;
}


int main()
{

    std::cin>>N>>M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin>>table[i][j];
        }
    }
    

    std::cout<<checkMax(table)<<std::endl;
    return 0;
}
