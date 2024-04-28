#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <deque>
#include <queue>
#include <stack>

using namespace std;


// Task 4

struct product
{
    double a = 0.000;
    double b = 0.00;
    int index = -1;
};

double m;
int n;
vector<product> arr;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> m >> n;

    for (int i = 0; i < n; ++i)
    {
        product temp;
        cin >> temp.a >> temp.b;

        temp.index = i;
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end(), [](product p1, product p2) {return (int)p1.b * 10000 > (int)p2.b * 10000 ; });

    double cur = 0;
    double lv = 0;
    int i = 0;
    for (; i < n; ++i)
    {
        if (cur == m)
        {
            break;
        }
        if (arr[i].a <= m - cur)
        {
            cur += arr[i].a;
            lv += arr[i].a * arr[i].b;
        }
        else
        {
            int temp = m - cur;
            cur += temp;
            lv += temp * arr[i].b;
            arr[i].a = temp;
        }
    }
    for (; i < n; ++i)
    {
        arr[i].a = 0;
    }

    sort(arr.begin(), arr.end(), [](product p1, product p2) {return p1.index < p2.index; });

    cout << fixed << setprecision(2) << lv << '\n';
    for (int j = 0; j < n; ++j)
    {
        cout << fixed << setprecision(3) << arr[j].a << '\n';
    }

}