#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

struct Flower {
    int val;
    vector<int> before;
    vector<int> after;
};

Flower gardenOrder[20000];

bool checkInside(vector<int> v, int target) {
    if (v.empty()) return true;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == target) return false;
        break;
    }

    return true;
}

bool check(Flower gardenOrder[], vector <int> g1) {
    for (int i = 0; i < g1.size(); i++)
    {
        for (int j = 0; j < g1.size(); j++)
        {
            if (j < i) {
                if (!checkInside(gardenOrder[i].after, g1[j])) {
                    return false;
                    break;
                }
                gardenOrder[i].before.push_back(g1[j]);
            }
            else if (j == i) {
                return false;
                break;
            }
            else if (j > i) {
                if (!checkInside(gardenOrder[i].before, g1[j])) {
                    return false;
                    break;
                }
                gardenOrder[i].after.push_back(g1[j]);
            }
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int steps = n;

    vector<vector<int>> gardens;

    while (n > 0) {
        int k;
        cin >> k;
        vector<int> flowers;
        while (k > 0) {
            int i;
            cin >> i;
            flowers.push_back(i);
            k--;
        }
        gardens.push_back(flowers);
        n--;
    }

    bool valid = true;
    for (int i = 0; i < steps; i++)
    {
        if (!check(gardenOrder, gardens.back())) {
            cout << false;
            valid = false;
            break;
        }
        gardens.pop_back();
    }

    if (valid) cout << true;

    return 0;
}