#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long n, k, ans;
long box[1000007];
long pref[1000007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> box[i];
        if (i == 0)
        {
            pref[i] = box[0];
        }
        pref[i] = pref[i - 1] + box[i];
    }

    long long thrill = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (j == i + 1)
            {
                thrill += box[i] * box[j];
            }
            else
            {

                thrill += (pref[j - 1] - pref[i - 1]) * box[j];
            }

            if (thrill >= k)
            {

                ans += n - j;
                thrill = 0;
                break;
            }
        }
    }

    cout << ans << endl;
}

