// O(n * log(n))

#include <bits/stdc++.h>

using namespace std;

#define MAX 2100000

int n, a[MAX], b[MAX];
int res[15][1024];
int maxlayer;
void merge(int l1, int r1, int l2, int r2, int layer)
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

    for(int i = l1; i <= r2; i++){
            a[i] = b[i - l1];
            res[layer][i] = a[i];
    }
    return;
}

void mergeSort(int l, int r, int layer)
{
    maxlayer = max(maxlayer, layer);
    if(l >= r)
    {
        res[layer][l] = a[l];
        return ;
    }
    int mid = (l + r) / 2; // l + (r - l) / 2
    mergeSort(l, mid, layer + 1);
    mergeSort(mid + 1, r, layer + 1);
    merge(l, mid, mid + 1, r, layer);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];

    mergeSort(0, n - 1, 0);

    for (int i = 0; i <= maxlayer; i++){
        for (int j = 0; j < n; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
