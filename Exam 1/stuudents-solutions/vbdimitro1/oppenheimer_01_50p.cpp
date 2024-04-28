#include <cstdio>
#include <vector>
using namespace std;

void quicksort(vector<unsigned>& arr)
{
    if (arr.size() <= 1)
        return;


    unsigned pivot = arr[0];

    vector<unsigned> smaller, bigger, equal;

    for (unsigned x : arr)
    {
        if (x > pivot)
            bigger.push_back(x);
        else if (x < pivot)
            smaller.push_back(x);
        else
            equal.push_back(x);
    }

    quicksort(smaller);
    quicksort(bigger);

    arr = smaller;
    for (unsigned x : equal)
        arr.push_back(x);
    for (unsigned x : bigger)
        arr.push_back(x);

    return;
}

int main()
{
    unsigned N;
    unsigned K;
    scanf("%u %u", &N, &K);

    vector<unsigned> arr;

    for (int i = 0; i < N; i++)
    {
        unsigned temp;
        scanf("%u", &temp);
        arr.push_back(temp);
    }

    quicksort(arr);

    unsigned max = 0;

    for (int i = 0; i < N; i++)
    {
        int j = i + 1;
        unsigned currSub = 1;

        while (j < N && ((arr[j] - arr[i]) <= K))
        {
            ++j;
            ++currSub;
        }

        if (currSub > max)
            max = currSub;
    }

    printf("%u", max);

    return 0;
}