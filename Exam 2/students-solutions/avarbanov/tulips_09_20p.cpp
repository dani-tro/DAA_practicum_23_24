#include <bits/stdc++.h>

int n, m;
int x;
int matrix[2][1010];


void calc(int x, int& count, bool first) {
    int last = -1;
    bool cn = true;
    for (int i = 0; i < m; i++) {
        bool row = (matrix[x][i] != last);
        bool column = matrix[(x+1)%2][i] != matrix[x][i];
        if  (row && column) {
            cn = false;
        }
        else if (first) {
            cn = false;
        }
        count += 1 - cn;
        //std::cout << x << "," << i << " count: " << count << '\n';
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
        if (i == 0 && n > 1) continue;
        if (i == 1) calc((i+1) % 2, curr, true);
        calc(i % 2, curr, false);
    }
    if (curr  > n * m) curr = n * m;
    std::cout << curr;
}