#include <bits/stdc++.h>

using namespace std;

long long A[102];
int n;
int a, b;
long long result = 0;

unordered_set<long long> st;
void calc(int ind, long long sum)
{
    // cout << ind << " " << sum << endl;
    if (sum > b)
    {
        // cout << "return line 14" << endl;
        return;
    }
    if (sum < a && ind == n - 1)
    {
        // cout << "return line 19" << endl;
        return;
    }

    if (sum >= a && sum <= b)
    {
        if (st.find(sum) != st.end())
        {
            // cout << "already in \n";
        }
        else
        {
            st.insert(sum);
            // cout << "result increase " << "ind: " << ind << " sum " << sum << endl;
            result++;
        }
    }
    for (int i = ind + 1; i < n; i++)
    {
        calc(i, sum + A[i]);
    }
    // cout << "res " << res << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++)
    {
        calc(i, A[i]);
    }

    cout << result;

    return 0;
}