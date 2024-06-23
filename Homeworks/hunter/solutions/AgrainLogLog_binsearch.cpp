/*
ID: espr1t
TASK: Agrain
KEYWORDS: Easy, Binary Search, Sorting
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
FILE* in = stdin; FILE* out = stdout;

int solve(int N, int L, int D, int X, int A, int B) {
    vector <int> points(N);
    for (int i = 0; i < N; i++) {
        points[i] = X;
        X = ((long long)X * A + B) % (L + 1);
    }
    int left = 1, right = N;
    while (left <= right) {
        int mid = (left + right) / 2;
        vector <int> tmp(points.begin(), points.begin() + mid);
        tmp.push_back(0);
        tmp.push_back(L);
        sort(tmp.begin(), tmp.end());
        bool okay = true;
        for (int i = 1; i < (int)tmp.size(); i++) {
            if (tmp[i] - tmp[i - 1] > D) {
                okay = false;
                break;
            }
        }
        if (okay)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return right + 1 <= N ? right + 1 : -1;
}

int main(void) {
    int N, L, D, X, A, B;
    fscanf(in, "%d %d %d", &N, &L, &D);
    fscanf(in, "%d %d %d", &X, &A, &B);
    fprintf(out, "%d\n", solve(N, L, D, X, A, B));
    return 0;
}
