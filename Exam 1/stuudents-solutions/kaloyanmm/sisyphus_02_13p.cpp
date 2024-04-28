#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    pair<int, int> path;

    int finalSum = 0;

    cin >> n >> m >> k;

    vector<pair<int, int>> difficulties;
    pair<int, int> pointPriority;

    vector<pair<int, int>> paths;

    for (int i = 0; i < n; i++)
    {
        pointPriority.first = 0;
        cin >> pointPriority.second;

        difficulties.push_back(pointPriority);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> path.first >> path.second;
        paths.push_back(path);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = paths[i].first - 1; j < paths[i].second; j++)
        {
            difficulties[j].first++;
        }
    }


    sort(difficulties.begin(), difficulties.end());
    
    while (k > 0) {
        difficulties.back().second--;
        if (difficulties.back().second == 0) {
            difficulties.pop_back();
        }

        k--;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = paths[i].first - 1; j < paths[i].second; j++)
        {
            finalSum += difficulties[j].second;
        }
    }

    if (finalSum < 0) finalSum = 0;
    cout << finalSum;

    return 0;
}