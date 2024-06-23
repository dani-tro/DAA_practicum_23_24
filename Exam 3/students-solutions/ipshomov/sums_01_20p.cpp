#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1e4;
int n, a, b, q;
long sums;
vector<int> numbers;
vector<int> used_n;
vector<int> tba;
bool used [10005];
long counter = 0;

int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> q;
        numbers.push_back(q);
    }

    sort(numbers.begin(), numbers.end());
    used_n.push_back(0);
    for (int i = 0; i < n; i++)
    {
        for (int number : used_n)
        {
            int curr = number + numbers[i];
            if (curr > b)
            {
                break;
            }
            else if (curr >= a && !used[curr])
            {
                used[curr] = true;
                counter++;
                tba.push_back(curr);
            }
        }

        for (int number : tba)
        {
            used_n.push_back(number);
        }
        tba.clear();
    }

    cout << counter << endl;

    return 0;
    
}
