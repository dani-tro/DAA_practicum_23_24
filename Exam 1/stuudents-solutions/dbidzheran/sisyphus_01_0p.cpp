#include <bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long k;
vector<point> arr;

struct point
{
    long long val;
    bool start = 0;
    bool end = 0;
    int goOver = 0; 
    size_t index = 0;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m >> k;
    for (size_t i = 0; i < n; ++i)
    {
        point temp;
        cin >> temp.val;
        temp.index = i;
        arr.push_back(temp);
    }
    for (size_t i = 0; i < m; ++i)
    {
        size_t temp1, temp2;
        cin >> temp1 >> temp2;
        arr[temp1 - 1].beg = true;
        arr[temp1 - 1].goOver++;
        arr[temp2 - 1].goOver++;
        arr[temp2 - 1].end = true;
    }
    size_t count = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i].beg)
        {
            count++;
        }
        if (arr[i].end)
        {
            count--;
        }
        arr[i].goOver = count;
    }

    sort(arr.begin(), arr.end(), [](const point& a, const point& b) {return a.goOver > b.goOver; });

    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i] >= k)
        {
            arr[i] -= k;
            break;
        }
        else
        {
            k -= arr[i];
            arr[i] = 0;
        }
    }

    sort(arr.begin(), arr.end(), [](const point& a, const point& b) {return a.index < b.index; });

    long long sum = 0;
    for (size_t i = 0; i < n; ++i)
    {
        sum += arr[i].val * arr[i].goOver;
    }
    cout << sum;
}