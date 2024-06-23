#include <iostream>

using namespace std;

bool arr[1000];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        for (int i = b; i >= 0; i--)
        {
            if (arr[i]) {
                arr[i + t] = true;
            }
        }
        arr[t] = true;
    }
    int counter = 0;
    for (int i = a; i <= b; i++)
    {
        if (arr[i])
        {
            counter++;
        }
    }
    cout << counter << endl;
}