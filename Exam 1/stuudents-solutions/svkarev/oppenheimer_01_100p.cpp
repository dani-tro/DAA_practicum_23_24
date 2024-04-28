#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n;
    uint64_t k;
    cin>>n>>k;
    vector<uint64_t> bombs(n,0);

    for (size_t i = 0; i < n; i++)
    {
        cin >> bombs[i];
    }
    sort(bombs.begin(), bombs.end());

    int l = 0;
    int r = 0;
    uint32_t cur_c = 0;
    uint32_t max_c = 0;
    

    while(r < n && l <= r)
    {
        if(bombs[r] - bombs[l] <= k)
        {
            r++;
            cur_c++;
        }
        else
        {
            if(cur_c > max_c)
                max_c = cur_c;

            do
            {
                l++;
                cur_c--;
            }while(l <= r && bombs[r] - bombs[l] > k);
        }
    }
    if(cur_c > max_c)
        max_c = cur_c;
    
    cout << max_c<<endl;

    return 0;
}

/*
10 4
5 9 3 1 2 7 8 9 5 8


1 2 3 5 5 7 8 8 9 9


*/