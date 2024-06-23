#include <iostream>
using namespace std;

int n, a, b;
int main()
{
    bool dp[100]{ false };
    dp[0] = true;
    int input[100];

    cin >> n >> a >> b;

    //init
    for (size_t i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        input[i] = temp;
        //dp[temp] = true;
    }
    //for (size_t i = 0; i < 100; i++)
    //{
    //    if (dp[i]) cout << i << " ";
    //}

    for (size_t i = 0; i < n; i++)
    {
        for (int j = 100 - 1; j >= 0; j--)
        {
            //if (j > b) continue;

            if (dp[j] && j + input[i] <= b)
            {
                dp[j + input[i]] = true;
                //cout << j + input[i] << " ";
            }
            //cout << endl;
        }
    }

    int count = 0;
    //for (size_t i = 0; i <= 99; i++)
    for (size_t i = a; i <= b; i++)
    {
        if (dp[i])
        {
            count++;
            //cout << i << " ";
        }
    }
    // << endl;
    cout << count << endl;
}