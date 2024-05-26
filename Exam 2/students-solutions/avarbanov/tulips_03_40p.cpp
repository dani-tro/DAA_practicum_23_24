#include <bits/stdc++.h>

int n, m;
int x;
int matrix[2][1010];


void calc(int x, int& count) {
    int last = -1;
    bool cn = true;
    for (int i = 0; i < m; i++) {
        if (matrix[x][i] != last && matrix[(x+1)%2][i] != matrix[x][i]) {
            cn = false;
        }
        count += 1 - cn;
        if (count < 0) count = 0;
        cn = true;
        last = matrix[x][i];
    }
}


int main() {
    std::cin >> n >> m;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        std::fill(matrix[i], matrix[i] + m + 1, -1);
        for (int j = 0; j < m; j++) {
            std::cin >> x;
            matrix[i%2][j] = x;
        }
        calc(i % 2, curr);
    }
    std::cout << curr;
}