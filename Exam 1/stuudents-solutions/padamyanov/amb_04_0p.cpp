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
    int dist[100000];
    bool rooms[100000];

    int sum = 0;

    for (size_t i = 0; i < n - 1; i++)
    {
        rooms[i] = false;
        cin >> dist[i];
        sum += dist[i];
    }
    rooms[n - 1] = false;

    double diff = (double)sum / (double)k;

    int currentSum = 0;
    double currentDiff = diff;
    for (size_t i = 0; i < n - 1; i++)
    {
        currentSum += dist[i];
        if (currentDiff <= currentSum)
        {
            currentDiff += diff;
            rooms[i] = true;
        }
    }
    //TVs are placed
    int maxDist = INT_MIN;
    int currentDist = 0;

    for (size_t i = 0; i < n - 1; i++)
    {
        if (rooms[i])
        {
            if (maxDist < currentDist)
                maxDist = currentDist;
            currentDist = 0;
            if (rooms[i + 1]) continue;
        }
        currentDist += dist[i];
    }
    if (maxDist < currentDist)
        maxDist = currentDist;

    cout << maxDist;
}