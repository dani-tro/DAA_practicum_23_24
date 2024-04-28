#include <bits/stdc++.h>
using namespace std;

long long n,k;

long long arr[100010];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // vector<int long long> v;

    cin >> n >> k;

    for(int long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr,arr+n);

    int long long l = 0;
    int long long r = n-1;

    long long count = 0;


    while(l <= r)
    {
        if(arr[r] -arr[l] > k)
        {
            l++;
        }
        else
        {
            r--;
            count++;
        }
    }


    // for(int i = 0; i < n; i++)
    // {
    //     if(arr[n-1] - arr[i] <= k)
    //     {
    //         count++;
    //     }
        
    // }

    cout << count << endl;

}