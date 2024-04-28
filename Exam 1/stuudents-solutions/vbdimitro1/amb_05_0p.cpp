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

    for (int i = 0; i < N - 1; i++)
    {
        unsigned temp;
        scanf("%u", &temp);
        arr.push_back(temp);

        sum += temp;
    }

    unsigned lo = 0;
    unsigned hi = sum;
    unsigned mid;

    while (lo <= hi)
    {
        unsigned currentTotal = 0;
        mid = lo + (hi - lo) / 2;
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

        if (total <= K)
        {
            if (hi != mid)
                hi = mid;
            else
                break;
        }
        else if (lo != mid)
        {
            lo = mid;
        }
        else
        {
            mid = hi;
            break;
        }
    }

    printf("%u", mid);

	return 0;
}