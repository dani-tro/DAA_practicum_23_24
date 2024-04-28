#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000000

int N, maxCnt = 0, cntMin = 0, cntMax = 0;
long long K, A[MAXN], maxA, minA;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>N>>K;

    for(int i = 0; i < N; i++)
    {
        cin>>A[i];
    }
    maxA = A[0]; minA = A[0];
    for(int i = 0; i < N; i++)
    {
        if(A[i] > maxA)
        {
            maxA = A[i];
        }
        if(A[i] < minA)
        {
            minA = A[i];
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(abs(maxA - A[i]) <= K)
        {
            cntMax++;
        }
        if((abs(minA - A[i])) <= K)
        {
            cntMin++;
        }
    }

    if(cntMax > cntMin)
    {
        cout<<cntMax<<endl;
    }
    else
    {
        cout<<cntMin<<endl;
    }


    return 0;
}
