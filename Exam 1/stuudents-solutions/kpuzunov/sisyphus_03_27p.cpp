#include <bits/stdc++.h>

using namespace std;

struct range
{
    int l;
    int r;
};
    int n, m, k;
    bool canOptimize = true;
    vector<int> a(100000);
    vector<range> b(1000000);

void findMostSeenAndSub()
{
    int indx = -1;
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
            continue;

        int count = 0;
        for(int j = 0; j < m; j++)
        {
            if((i + 1) <= b[j].r && (i + 1) >= b[j].l)
            {
                count++;
            }
        }
        if(max < count)
        {
            max = count;
            indx = i;
        }

        if(max == m)
            break;
    }

    if(indx == -1)
    {
        canOptimize = false;
        k = 0;
        return;
    }

    if(k <= a[indx])
    {
        a[indx] -= k;
        k = 0;
    }
    else
    {
        int temp = a[indx];
        a[indx] = 0;
        k -= temp;
    }
};

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

    while(k > 0)
    {
        if(canOptimize)
            findMostSeenAndSub();
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