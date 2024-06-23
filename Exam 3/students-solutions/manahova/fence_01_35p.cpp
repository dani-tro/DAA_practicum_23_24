#include <bits/stdc++.h>
using namespace std;

#define MAX 2005
#define MOD 1000000007

int sum;
long long dp_asc[MAX][MAX], dp_desc[MAX][MAX], ans;

long long calc_asc(int s, int f);
long long calc_desc(int s, int f);

long long calc_asc(int s, int f)
{   
    if (dp_asc[s][f] == -1)
    {
        dp_asc[s][f] = 0;

        if (f == s)
        {
            dp_asc[s][f] = 1;
            return dp_asc[s][f];
        }
        else if (f > s || f == 0)
        {
            dp_asc[s][f] = 0;
            return 0;
        }

        for (int i = f + 1; i <= s - f; i++)
        {
            dp_asc[s][f] += calc_desc(s - f, i);
            dp_asc[s][f] %= MOD;
        }
    }
    
    //cout << "dp_asc[" << s << "][" << f << "] = " << dp_asc[s][f] << endl;
    return dp_asc[s][f];
}

long long calc_desc(int s, int f)
{
    if (dp_desc[s][f] == -1)
    {
        dp_desc[s][f] = 0;

        if (f == s)
        {
            dp_desc[s][f] = 1;
            return dp_desc[s][f];
        }

        else if (f > s || f == 0)
        {
            dp_desc[s][f] = 0;
            return 0;
        }

        for (int i = 1; i < f; i++)
        {
            dp_desc[s][f] += calc_asc(s - f, i);
            dp_desc[s][f] %= MOD;
        }       
    }

    //cout << "dp_desc[" << s << "][" << f << "] = " << dp_desc[s][f] << endl;
    return dp_desc[s][f];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> sum;

    for (int i = 0; i <= sum; i++)
    {
        fill(dp_asc[i], dp_asc[i] + sum + 1, -1);
        fill(dp_desc[i], dp_desc[i] + sum + 1, -1);
    }

    for (int i = 1; i <= sum; i++)
    {
        ans += calc_asc(sum, i) + calc_desc(sum, i);
    }

    ans--;
    cout << ans << endl;

    return 0;
}