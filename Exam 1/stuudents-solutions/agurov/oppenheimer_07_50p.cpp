#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<long long> atoms(n);
    for (auto &x : atoms)
    {
        cin >> x;
    }
    sort(atoms.begin(), atoms.end());

    long long currMax = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (atoms[j] - atoms[i] <= k && j - i + 1 > currMax)
            {
                currMax = j - i + 1;
            }
        }
    }
    cout << currMax << endl;
    // 1 1 2 3 4 6 8 9 10
    // 1 1 2 3 5 5 7 8 8 9 9
}