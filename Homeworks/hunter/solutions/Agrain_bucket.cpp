/*
ID: espr1t
TASK: Agrain
KEYWORDS: Medium, Linked list, Buckets
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
FILE* in = stdin; FILE* out = stdout;

int solve(int N, int L, int D, int X, int A, int B) {
    if ((long long)(N + 1) * D < (long long)L)
        return -1;
    vector <int> minn(L / D + 1, L), maxx(L / D + 1, 0);

    int drop = 0, rem = L / D;
    while (rem > 0 && ++drop <= N) {
        int idx = X / D;
        if (idx - 1 >= 0     && minn[idx] - maxx[idx - 1] > D && X - maxx[idx - 1] <= D) rem--;
        if (idx + 1 <= L / D && minn[idx + 1] - maxx[idx] > D && minn[idx + 1] - X <= D) rem--;
        minn[idx] = min(minn[idx], X), maxx[idx] = max(maxx[idx], X);
        X = ((long long)X * A + B) % (L + 1);
    }
    return drop > N ? -1 : drop;
}

int main(void) {
    int N, L, D, X, A, B;
    fscanf(in, "%d %d %d", &N, &L, &D);
    fscanf(in, "%d %d %d", &X, &A, &B);
    fprintf(out, "%d\n", solve(N, L, D, X, A, B));
    return 0;
}
