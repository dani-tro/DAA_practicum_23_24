#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int a[100000];

    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                std::swap(a[j + 1], a[j]);
            }
        }
    }
    int currentMin = 0;
    int currentMax = n - 1;

    int currentDiff = a[currentMax] - a[currentMin];

    while (currentDiff > k)
    {
        //std::cout << currentDiff;
        if (a[currentMax] - a[currentMax - 1] >
            a[currentMin + 1] - a[currentMin])
        {
            currentMax -= 1;
            currentDiff = a[currentMax] - a[currentMin];
            continue;
        }
        currentMin += 1;
        currentDiff = a[currentMax] - a[currentMin];
    }

    //cout << endl << currentMin << endl << currentMax << endl;

    std::cout << currentMax - currentMin + 1;

}