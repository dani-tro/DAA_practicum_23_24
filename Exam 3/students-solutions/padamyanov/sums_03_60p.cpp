#include <iostream>
using namespace std;

int n, a, b;
int main()
{
    bool dp[100]{ false };
    int input[100];

    cin >> n >> a >> b;

    //init
    for (size_t i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        input[i] = temp;
        dp[temp] = true;
    }
    //for (size_t i = 0; i < 100; i++)
    //{
    //    if (dp[i]) cout << i << " ";
    //}

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 100; j++)
        {
            if (j == i) continue;

            if (dp[j] && dp[j + input[i]] <= b)
            {
                dp[j + input[i]] = true;
            }
        }
    }

    int count = 0;
    for (size_t i = a; i <= b; i++)
    {
        if (dp[i]) count++;
    }
    cout << count << endl;
}