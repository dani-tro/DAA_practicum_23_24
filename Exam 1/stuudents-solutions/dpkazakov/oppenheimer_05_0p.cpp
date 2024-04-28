#include<iostream>
#include<algorithm>
using namespace std;


const int MAX_SIZE = 10000;
long long atoms[MAX_SIZE];

int main()
{
    long long n, k, i;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> atoms[i];
    }

    mysort(atoms, n);
    //10 4
    //5 9 3 1 2 7 8 9 5 8
    //1 2 3 5 5 7 8 8 9 9
    i = 0;
    while (i < n - 1)
    {
        if (atoms[n - 1] - atoms[i] > k)
        {
            i++;
        }
        else
        {
            break;
        }
    }
    cout << n - i;
    return 0;
}