#include <bits/stdc++.h>

using namespace std;

struct range
{
    int l;
    int r;
};
    int n, m, k;
    vector<int> a(100000);
    vector<range> b(1000000);

int findMostComon()
{
    int max = 0, indx = -1;
    for(int i = 0 ; i < n; i++)
    {
        if(a[i] == 0)
            continue;
            
        int count = 0;
        for(int j = 0; j < m; j++)
        {
            if(i + 1 <= b[j].r && i + 1 >= b[j].l)
                count++;
        }

        if(max < count)
        {
            max = count;
            indx = i;
        }

        if(max == m)
            break;
    }

    return indx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int i = 0 ; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0 ; i < m; i++)
    {
        cin >> b[i].l >> b[i].r;
    }

//===================================================================

    int indx;
    while(k > 0)
    {
        indx = findMostComon();

        if(indx == -1)
            break;
        if(a[indx] >= k)
        {
            a[indx] -= k;
            k = 0;
        }
        else
        {
            k -= a[indx];
            a[indx] = 0;
        }
    }

    if(indx == -1)
    {
        cout << 0;
        return 0;
    }
    
    int result = 0;
    for(int i = 0; i < m; i++)
    {
        int j = b[i].l - 1;
        while(j < b[i].r)
        {
            result += a[j];
            j++;
        }
    }
    
    cout << result;
}