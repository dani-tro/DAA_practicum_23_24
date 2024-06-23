#include <iostream>
#include <climits>

using namespace std;

#define MAX 100100
#define MAXMOVES 128

int n, k, a[MAX], m[MAXMOVES], minMove = MAX;
long long dp[MAX];
bool calculated[MAX];

int idx(int x, int y)
{
    return x + n*y;
}

long long calc(int l, int r)
{
    if(l>=r) return 0;
    if(r-l <= minMove) return a[l] + a[r];
    if(calculated[idx(l,r)]) return dp[(idx(l,r))];
    calculated[idx(l,r)] = true;

    long long ans = a[l] + a[r];
    for(int i = 0; i<k; ++i)
    {
        ans = max(ans, a[l] + calc(l+m[i], r));
        ans = max(ans, a[r] + calc(l, r-m[i]));
    }

    return dp[idx(l,r)] = ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    for(int i=0;i<k;++i)
    {
        cin >> m[i];
        if(minMove > m[i])
            minMove = m[i];
    }

    cout << calc(1,n) << endl; 

    return 0;
}