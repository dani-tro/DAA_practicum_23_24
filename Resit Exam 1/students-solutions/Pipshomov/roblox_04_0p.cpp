#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long n, k, ans;
long long box[1000007];
long long pref[1000007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    cin >> box[0];
    pref[0] = box[0];
    for (int i = 1; i < n; i++)
    {
        cin >> box[i];
        pref[i] = pref[i - 1] + box[i];
    }

    long long thrill = 0;
    long left=-1;
    for (int i = 0; i < n; i++)
    {
        if (i < left)
        {
            for (int j = left-1; j < n; ++j)
            {
                if (j == i + 1)
                {
                    thrill += box[i] * box[j];
                }
                else
                {
                    thrill += (pref[j - 1] - (i != 0 ? pref[i - 1] : 0)) * box[j];
                }

                if (thrill >= k)
                {
                    left = j;
                    ans += n - j;
                    thrill = 0;
                    break;
                }
            }
        }
        else
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (j == i + 1)
                {
                    thrill += box[i] * box[j];
                }
                else
                {
                    thrill += (pref[j - 1] - (i != 0 ? pref[i - 1] : 0)) * box[j];
                }

                if (thrill >= k)
                {
                    left = j;
                    ans += n - j;
                    thrill = 0;
                    break;
                }
            }
        }
        thrill = 0;
    }

    cout << ans << endl;
}

