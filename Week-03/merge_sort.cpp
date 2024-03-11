// O(n * log(n))

#include <bits/stdc++.h>

using namespace std;

#define MAX 2100000

int n, a[MAX], b[MAX];


void merge(int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2, idx = 0;
    while(i <= r1 && j <= r2)
    {
        if(a[i] >= a[j])
        {
            b[idx] = a[j];
            j++;
        }
        else
        {
            b[idx] = a[i];
            i++;
        }
        idx++;
    }
    for(; i <= r1; i++)
    {
        b[idx] = a[i];
        idx++;
    }
    for(; j <= r2; j++)
    {
        b[idx] = a[j];
        idx++;
    }

    for(int i = l1; i <= r2; i++)a[i] = b[i - l1];
    return;
}

void mergeSort(int l, int r)
{
    if(l >= r)
    {
        return ;
    }
    int mid = (l + r) / 2; // l + (r - l) / 2
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, mid + 1, r);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];

    mergeSort(0, n - 1);

    for(int i = 0; i < n; i++)cout << a[i] << " ";
    cout << endl;

    return 0;
}


/*

10
8 3 42 21 -3 7 6 1 13 29

*/
