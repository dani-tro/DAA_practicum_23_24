#include <iostream>
#include <vector>

#include <algorithm> 
#include <deque>
#include <queue>
#include <stack>

using namespace std;

int n;
int k;
std::vector<int> arr;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);   

    cin >> n >> k;
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), [](int a, int b) {return a > b; });

    int maxcount = 0;
    int count = 1;
    int res = 0;
    for (int i = 0; i < n - count + 1; ++i)
    {
        while (i + count - 1 < n)
        {
            res = arr[i] - arr[i + count - 1];
            if (res <= k)
            {
                ++count;
            }
            else
            {
                --count;
                break;
            }
        }
        if (count > maxcount) maxcount = count;
    }

    cout << maxcount << '\n';
};

//10 4
// 5 9 3 1 2 7 8 9 5 8

// 9 9 8 8 7 5 5 3 2 1