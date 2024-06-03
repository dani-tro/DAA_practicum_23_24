#include <bits/stdc++.h>

using namespace std;

#define MAX 52

int n, a[MAX], ans = INT_MAX / 2;

void rec(int idx, int delta, int thrown)
{
    if(idx == n + 1)
    {
        if(delta == 0)
        {
			ans = min(ans, thrown);
        }
        return;
    }	
    
    rec(idx + 1, delta + a[idx], thrown);
    rec(idx + 1, delta - a[idx], thrown);
    rec(idx + 1, delta, thrown + a[idx]);
    
    return;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    rec(1, 0, 0);
    
    cout << ans << endl;
    
    return 0;
}

