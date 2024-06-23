#include <cmath>
#include <climits>
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int const MAXN = 100001;
int const MAXK = 1001;



int line[MAXN];
int lineK[MAXK];
int lineBeg[MAXN];
int lineEnd[MAXN];

//int const minVal = -100001;

void calc1(int N,int K) {
    for(int i=0;i<N;i++){
        for (int j = 0; j < K; j++) {
            if (i - lineK[j] < 0);
            else { lineBeg[i] = max(lineBeg[i], line[i] + lineBeg[i - lineK[j]]); }
        }
    }
}

void calc2(int N, int K) {
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < K; j++) {
            if (i + lineK[j] > N-1);
            else { lineEnd[i] = max(lineEnd[i], line[i] + lineEnd[i + lineK[j]]); }
        }
    }
}

int main()
{   
    for (int i = 0; i < MAXN; i++) {
        lineBeg[i] = -100001;
    }
    for (int i = 0; i < MAXN; i++) {
        lineEnd[i] = -100001;
    }

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> line[i];
    }
    for (int i = 0; i < K; i++) {
        cin >> lineK[i];
    }
    lineBeg[0] = line[0];
    lineEnd[N - 1] = line[N - 1];
    calc1(N, K);
    calc2(N, K);
    
    int currMaxBeg = lineBeg[0];
    for (int i = 1; i < N; i++) {
        if (lineBeg[i] > currMaxBeg) {
            currMaxBeg = lineBeg[i];
        }
        lineBeg[i] = currMaxBeg;
    }
    int currMaxEnd = lineEnd[N-1];
    for (int i = N- 1; i >=0; i--) {
        if (lineEnd[i] > currMaxEnd) {
            currMaxEnd = lineEnd[i];
        }
        lineEnd[i] = currMaxEnd;
    }

    /*
    for (int i = 0; i < N; i++) {
        cout << lineBeg[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << lineEnd[i] << " ";
    }
    */
    int totalMax = line[0] + line[N - 1];
    for (int i = 0; i < N; i++) {
        if (totalMax < lineBeg[i] + lineEnd[i]) { totalMax = lineBeg[i] + lineEnd[i]; }
    }
    cout << totalMax;

}