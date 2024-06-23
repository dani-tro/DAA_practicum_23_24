#include <iostream>
#include <stdio.h>
#include <stack>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <climits>

const int MAXN = 105;
const int MAXS = 1e4 + 5;
int n, a, b;
int arr[MAXN];
bool s[MAXN][MAXS];

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    std::cin >> n >> a >>b;
    for (int i = 1; i <= n; i++) std::cin >> arr[i];
    for (int i = 0; i <= n; i++) s[i][0] = 1;
    for (int j = 1; j <= b; j++) s[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            s[i][j] = s[i - 1][j];
            if (j - arr[i] >= 0) s[i][j] += s[i - 1][j - arr[i]];
        }
    }
    int ans = 0;
    for (int j = a; j <= b; j++) ans += s[n][j];

    std::cout << ans << "\n";

    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            std::cout << s[i][j] << " ";
        }
        std::cout << "\n";
    }*/
}