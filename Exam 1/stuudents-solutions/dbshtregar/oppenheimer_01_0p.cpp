#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000000

int N, maxCnt = 0;
long long K, A[MAXN], maxA;
int start, finish;

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
    maxA = A[0];
    for(int i = 0; i < N; i++)
    {
        if(A[i] > maxA)
        {
            maxA = A[i];
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(abs(maxA - A[i]) <= K)
        {
            maxCnt++;
        }
    }

    cout<<maxCnt<<endl;

    return 0;
}
