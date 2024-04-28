#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void quicksortmod1(vector<unsigned>& arr, vector<bool>& pt)
{
    if (arr.size() <= 1)
        return;

    unsigned size = arr.size();

    unsigned pivot = arr[0];

    vector<unsigned> smaller, bigger, equal;
    vector<bool> smallerpt, biggerpt, equalpt;

    for (unsigned i = 0; i < size; i++)
    {
        if (arr[i] > pivot)
        {
            bigger.push_back(arr[i]);
            biggerpt.push_back(pt[i]);
        }
        else if (arr[i] < pivot)
        {
            smaller.push_back(arr[i]);
            smallerpt.push_back(pt[i]);
        }
        else
        {
            equal.push_back(arr[i]);
            equalpt.push_back(pt[i]);
        }
    }

    quicksortmod1(smaller, smallerpt);
    quicksortmod1(bigger, biggerpt);

    arr = smaller;
    pt = smallerpt;

    unsigned eqSize = equal.size();
    unsigned bgSize = bigger.size();
    for (unsigned i = 0; i < eqSize; i++)
    {
        arr.push_back(equal[i]);
        pt.push_back(equalpt[i]);
    }
    for (unsigned i = 0; i < bgSize; i++)
    {
        arr.push_back(bigger[i]);
        pt.push_back(biggerpt[i]);
    }

    return;
}

void quicksortmod2(vector<unsigned>& arr, vector<unsigned>& pt)
{
    if (arr.size() <= 1)
        return;

    unsigned size = arr.size();

    unsigned pivot = arr[0];

    vector<unsigned> smaller, bigger, equal;
    vector<unsigned> smallerpt, biggerpt, equalpt;

    for (unsigned i = 0; i < size; i++)
    {
        if (arr[i] > pivot)
        {
            bigger.push_back(arr[i]);
            biggerpt.push_back(pt[i]);
        }
        else if (arr[i] < pivot)
        {
            smaller.push_back(arr[i]);
            smallerpt.push_back(pt[i]);
        }
        else
        {
            equal.push_back(arr[i]);
            equalpt.push_back(pt[i]);
        }
    }

    quicksortmod2(smaller, smallerpt);
    quicksortmod2(bigger, biggerpt);

    arr = bigger;
    pt = biggerpt;

    unsigned eqSize = equal.size();
    unsigned smSize = smaller.size();
    for (unsigned i = 0; i < eqSize; i++)
    {
        arr.push_back(equal[i]);
        pt.push_back(equalpt[i]);
    }
    for (unsigned i = 0; i < smSize; i++)
    {
        arr.push_back(smaller[i]);
        pt.push_back(smallerpt[i]);
    }

    return;
}

int main()
{
	unsigned N;
	unsigned M;
	unsigned K;

	scanf("%u %u %u", &N, &M, &K);

	vector<unsigned> diffArr;

	for (int i = 0; i < N; i++)
	{
		unsigned temp;
	
		scanf("%u", &temp);
		diffArr.push_back(temp);
	}

    vector<unsigned> coordsArray;
    vector<bool> isEndpointArray;

    for (int i = 0; i < M; i++)
    {
        unsigned x1, x2;

        scanf("%u %u", &x1, &x2);
        coordsArray.push_back(x1);
        coordsArray.push_back(x2);
        isEndpointArray.push_back(false);
        isEndpointArray.push_back(true);
    }

    quicksortmod1(coordsArray, isEndpointArray);

    vector<unsigned> interCounterArray;
    vector<unsigned> interIndexArray;

    unsigned interCounter = 0;
    unsigned it = coordsArray[0];
    unsigned end = coordsArray[2 * M - 1];
    unsigned index = 0;

    while (it <= end)
    {
        bool met = false;
        if(it == coordsArray[index])
        {
            if (!isEndpointArray[index])
            {
                ++interCounter;
                met = true;

                while (index + 1 < 2 * M)
                {
                    if (coordsArray[index] == coordsArray[index + 1])
                    {
                        ++index;
                        ++interCounter;
                    }
                    else
                        break;
                }
            }
        }

        if(interCounter)
        {
            interCounterArray.push_back(interCounter);
            interIndexArray.push_back(it);
        }

        if(it == coordsArray[index])
        {
            if (isEndpointArray[index])
            {
                --interCounter;
                met = true;

                while (index + 1 < 2 * M)
                {
                    if (coordsArray[index] == coordsArray[index + 1])
                    {
                        ++index;
                        --interCounter;
                    }
                    else
                        break;
                }
            }
        }
        
        if (met)
            ++index;
        ++it;
    }

    quicksortmod2(interCounterArray, interIndexArray);


    unsigned currInterIndex = 0;
    unsigned indexArraySize = interIndexArray.size();

    while (K > 0 && currInterIndex < indexArraySize)
    {
        if (diffArr[interIndexArray[currInterIndex] - 1] > 0)
        {
            --diffArr[interIndexArray[currInterIndex] - 1];
            --K;
        }
        else
            ++currInterIndex;
    }

    unsigned result = 0;

    for (unsigned i = 0; i < indexArraySize; i++)
    {
        result += interCounterArray[i] * diffArr[interIndexArray[i] - 1];
    }

    printf("%u", result);

	return 0;
}