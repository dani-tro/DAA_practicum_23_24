#include <bits/stdc++.h>

using namespace std;

int n;
long long k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    vector<long long> atoms(n);

    for (long long &x : atoms)
    {
        cin >> x;
    }

    sort(atoms.begin(), atoms.end());

    int l = 0, r = 0;
    int result{};

    for (int i = 0; i < n; ++i)
    {
        while (r < n && atoms[r] - atoms[l] <= k)
        {
            r++;
        }

        l++;

        result = max(result, r - l + 1);
        if (r == n)
        {
            break;
        }
    }

    cout << result << endl;

    return 0;
};