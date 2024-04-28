#include <bits/stdc++.h>
using namespace std;

int long long n,k;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    vector<int long long> v;

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        int long long t;
        cin >> t;
        v.push_back(t);
    }
    
    sort(v.begin(),v.end());

    int long long l = 0;
    int long long r = v.size()-1;

    while(l < r && v[r] - v[l] > k)
    {
        l++;
    }

    cout << r-l+1 << endl;

}