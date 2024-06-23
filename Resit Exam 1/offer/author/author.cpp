//Task: shop
//Author: Kinka Kirilova-Lupanova

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, a[100000];
    scanf("%d%d", &n, &k);
    
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a+n, greater<int>());
    int res = 0;
    for (int i = 0; i < n; ++i)
        if (i % k != k - 1)
            res += a[i];
    printf("%d\n", res);

    return 0;
}
