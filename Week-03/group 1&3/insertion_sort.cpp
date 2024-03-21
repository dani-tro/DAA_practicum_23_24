// O(n^2)

# include <bits/stdc++.h>
using namespace std;

#define MAX 1024

int n, a[MAX];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(j > 0 && a[j] < a[j - 1])
        {
            swap(a[j], a[j - 1]);
            j--;
        }
        for(int j = 0; j < n; j++)cout << a[j] << " ";
        cout << endl;
    }
    return 0;
}
