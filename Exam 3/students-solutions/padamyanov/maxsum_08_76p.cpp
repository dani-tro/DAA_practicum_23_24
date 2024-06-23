#include <iostream>
#include <climits>
using namespace std;

int n, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dpLeft[100000];
    int dpRight[100000];
    bool dpLeftReached[100000];
    bool dpRightReached[100000];

    int numbers[100000];
    uint16_t moves[1000];

    //init
    cin >> n >> k;
    for (size_t i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    for (size_t i = 0; i < k; i++)
    {
        cin >> moves[i];
    }
    dpLeft[0] = numbers[0];
    dpLeftReached[0] = true;

    dpRight[n - 1] = numbers[n - 1];
    dpRightReached[n - 1] = true;

    for (size_t i = 1; i < n - 1; i++)
    {
        dpLeft[i] = dpRight[i] = INT_MIN;
    }

    //filling dpLeft
    for (int i = 1; i < n - 1; i++)
    {
        dpLeftReached[i] = false;
        for (size_t j = 0; j < k; j++)
        {
            if (i - moves[j] >= 0 && dpLeftReached[i - moves[j]])
            {
                if (dpLeft[i] < dpLeft[i - moves[j]] + numbers[i])
                {
                    dpLeftReached[i] = true;
                    dpLeft[i] = dpLeft[i - moves[j]] + numbers[i];
                }
            }
        }
    }
    //for (size_t i = 0; i < n - 1; i++)
    //{
    //    //if()
    //    cout << dpLeft[i] << " ";
    //}
    //cout << endl;
    
    //filling dpRight
    for (int i = n - 2; i > 0; i--)
    {
        dpRightReached[i] = false;
        for (size_t j = 0; j < k; j++)
        {
            if (i + moves[j] >= 0 && dpRightReached[i + moves[j]])
            {
                if (dpRight[i] < dpRight[i + moves[j]] + numbers[i])
                {
                    dpRightReached[i] = true;
                    dpRight[i] = dpRight[i + moves[j]] + numbers[i];
                }
            }
        }
    }
    //for (size_t i = 1; i < n; i++)
    //{
    //    cout << dpRight[i] << " ";
    //}

    int max = INT_MIN;

    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 1; j < n; j++)
        {
            if (j <= i || !dpLeftReached[i] || !dpRightReached[j]) continue;

            if (max < dpLeft[i] + dpRight[j])
            {
                max = dpLeft[i] + dpRight[j];
            }
        }
    }

    cout << max << endl;

}