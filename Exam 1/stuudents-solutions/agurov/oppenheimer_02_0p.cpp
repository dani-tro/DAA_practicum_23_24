#include <bits/stdc++.h>
using namespace std;

long long fun(long long l, long long r, vector<long long> &atoms, long long k)
{
    while (l < r)
    {
        if (atoms[r] - atoms[l] <= k)
        {
            return r - l + 1;
        }
        else if (atoms[r - 1] - atoms[l] < atoms[r] - atoms[l + 1])
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return 0;
}

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
    long long l = 0, r = n - 1;
    cout << fun(l, r, atoms, k) << endl;
    // 1 1 2 3 4 6 8 9 10
}