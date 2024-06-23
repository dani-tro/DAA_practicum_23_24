/*
ID: espr1t
TASK: Agrain
KEYWORDS: Medium, Priority Queue
*/

#include <cstdio>
#include <queue>

using namespace std;
FILE* in = stdin; FILE* out = stdout;

int solve(int N, int L, int D, int X, int A, int B) {
    priority_queue < int, vector<int>, greater<int> > q;
    int pos = 0, at = 0;
    while (pos + D < L && at < N) {
        at++;
        if (X > pos) {
            q.push(X);
            while (!q.empty() && pos + D >= q.top()) {
                pos = q.top();
                q.pop();
            }
        }
        X = ((long long)X * A + B) % (L + 1);
    }
    return pos + D >= L ? at : -1;
}

int main(void) {
    int N, L, D, X, A, B;
    fscanf(in, "%d %d %d", &N, &L, &D);
    fscanf(in, "%d %d %d", &X, &A, &B);
    fprintf(out, "%d\n", solve(N, L, D, X, A, B));
    return 0;
}
