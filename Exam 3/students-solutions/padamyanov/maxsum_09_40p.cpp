#include <iostream>
#include <climits>
using namespace std;

int n, k;

int findMaxIndex(int begin, int end, const int* arr)
{
    int maxIndex = begin;
    for (size_t i = begin + 1; i < end; i++)
    {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dpLeft[1000];
    int dpRight[1000];
    bool dpLeftReached[1000];
    bool dpRightReached[1000];

    int numbers[1000];
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

    //int max = INT_MIN;

    //for (size_t i = 0; i < n - 1; i++)
    //{
    //    for (size_t j = 1; j < n; j++)
    //    {
    //        if (j <= i || !dpLeftReached[i] || !dpRightReached[j]) continue;

    //        if (max < dpLeft[i] + dpRight[j])
    //        {
    //            max = dpLeft[i] + dpRight[j];
    //        }
    //    }
    //}

    //cout << max << endl;

    int leftMaxIndex = findMaxIndex(0, n - 1, dpLeft);
    int rightMaxIndex = findMaxIndex(1, n, dpRight);

    while (leftMaxIndex >= rightMaxIndex)
    {
        //cout << leftMaxIndex << endl << rightMaxIndex << endl << endl;
        int newLeftMaxIndex = findMaxIndex(0, leftMaxIndex, dpLeft);
        int newRightMaxIndex = findMaxIndex(rightMaxIndex + 1, n, dpRight);

        //cout << newLeftMaxIndex << endl << newRightMaxIndex << endl << endl;

        if (dpLeft[leftMaxIndex] - dpLeft[newLeftMaxIndex] > 
            dpRight[rightMaxIndex] - dpRight[newRightMaxIndex])
        {
            rightMaxIndex = newRightMaxIndex;
        }
        else
        {
            leftMaxIndex = newLeftMaxIndex;
        }
    }
    //cout << leftMaxIndex << endl << rightMaxIndex << endl << endl;

    cout << dpLeft[leftMaxIndex] + dpRight[rightMaxIndex];

}