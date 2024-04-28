#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

//const unsigned long long MAX_VALUE = 100000;
//int atoms[MAX_VALUE];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, val;
    cin >> n >> k;

    vector<unsigned long long> atoms;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        atoms.push_back(val);
    }

    sort(atoms.begin(), atoms.end());

    int atomNum = 0;
    int currNum = 0;

    for (int i = 0; i < n; i++)
    {
        currNum = 0;
        for (int j = i; j < n; j++)
        {
            if (atoms[j] - atoms[i] <= k) {
                currNum++;
                if (currNum > atomNum) atomNum = currNum;
            }
            else break;
        }
    }

    cout << atomNum;

    return 0;
}