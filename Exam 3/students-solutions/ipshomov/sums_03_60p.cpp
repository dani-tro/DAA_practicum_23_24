#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, a, b, q;
vector<int> numbers;
vector<int> used_n;
vector<int> tba;
bool used [10005];
long counter = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
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
            }
            tba.push_back(curr);
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
