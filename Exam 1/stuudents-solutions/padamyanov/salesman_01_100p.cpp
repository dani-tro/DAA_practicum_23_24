#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <iomanip> 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    double weight[100];
    double weightTaken[100];
    double price[100];

    for (size_t i = 0; i < n; i++)
    {
        cin >> weight[i] >> price[i];
        weightTaken[i] = 0;
    }

    double currentWeight = 0;
    double currentPrice = 0;
    while (1)
    {
        int maxIndex = 0;
        for (size_t i = 1; i < n; i++)
        {
            if (price[i] > price[maxIndex])
                maxIndex = i;
        }
        currentWeight += weight[maxIndex];

        if (currentWeight >= m)
        {
            currentPrice += 
                (m - (currentWeight - weight[maxIndex])) * price[maxIndex];
            weightTaken[maxIndex] = m - (currentWeight - weight[maxIndex]);
            break;
        }
        currentPrice += weight[maxIndex] * price[maxIndex];
        price[maxIndex] = 0;
        weightTaken[maxIndex] = weight[maxIndex];
    }
    cout << fixed << setprecision(2) << currentPrice << endl;

    for (size_t i = 0; i < n; i++)
    {
        cout << fixed << setprecision(3) << weightTaken[i] << endl;
    }

}