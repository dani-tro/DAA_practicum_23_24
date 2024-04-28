#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> distances; int val;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> val;
        distances.push_back(val);
    }

    bool case2 = true;
    int power = 1;
    for (int i = 0; i < n - 1; i++)
    {   
        if (distances[i] != 2 * power) {
            case2 = false;
            break;
        }
        power *= 2;
    }

    if (case2) cout << distances.back();

    return 0;
}