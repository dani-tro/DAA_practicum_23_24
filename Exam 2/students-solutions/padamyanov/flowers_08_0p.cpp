#include <iostream>
using namespace std;

int indexOf(size_t element, const size_t* arr, int startIdx, int endIdx)
{
    for (int i = startIdx; i < endIdx; i++)
    {
        if (element == arr[i]) return i;
    }
    return -1;
}
void insertAt(size_t element, size_t* arr, int& size, int index)
{
    size++;
    for (int i = size - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t flowers[200000];
    bool answer = true;
    size_t k;
    cin >> k;

    int size = 0;
    for (size_t i = 0; i < k; i++)
    {
        int currSize = 0;
        cin >> currSize;

        size_t currNum = 0;

        for (size_t j = 0; j < currSize; j++)
        {
            cin >> currNum;
            int startIndex = 0;
            int index = indexOf(currNum, flowers, startIndex, size);
            if (index == -1)
            {
                /*flowers[size++] = currNum;*/
                insertAt(currNum, flowers, size, startIndex);
                startIndex++;
                if (indexOf(currNum, flowers, 0, startIndex - 1) != -1)
                {
                    //cout << j << endl;
                    answer = false;
                }
            }
            else
            {
                startIndex = index + 1;
            }

        }
    }
    //for (size_t i = 0; i < size; i++)
    //{
    //    cout << flowers[i] << " ";
    //}
    //cout << endl;

    cout << answer;
}