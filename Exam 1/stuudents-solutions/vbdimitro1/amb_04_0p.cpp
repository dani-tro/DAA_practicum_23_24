#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    unsigned N;
    unsigned K;
    scanf("%u %u", &N, &K);

    vector<unsigned> arr;
    unsigned sum = 0;
    unsigned max = 0;

    for (int i = 0; i < N - 1; i++)
    {
        unsigned temp;
        scanf("%u", &temp);
        arr.push_back(temp);

        sum += temp;

        if (max < temp)
            max = temp;
    }

    unsigned lo = max;
    unsigned hi = sum;
    unsigned mid;

    while (lo <= hi)
    {
        unsigned currentTotal = 0;
        mid = (lo + hi) / 2;
        unsigned total = 0;

        for (unsigned x : arr)
        {
            currentTotal += x;
            if (currentTotal > mid)
            {
                ++total;
                currentTotal = x;
            }
        }

        if (total > K)
        {
            lo = mid;
        }
        else if (hi != mid)
        {
            hi = mid;
        }
        else
            break;
    }

    printf("%u", mid);

	return 0;
}