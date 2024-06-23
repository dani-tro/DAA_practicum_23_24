#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> moves;
vector<int> points;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    moves.resize(k);
    points.resize(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> points[i];
    }

    for (size_t i = 0; i < k; i++)
    {
        cin >> moves[i];
    }

    vector<int64_t> max_suml(n, INT64_MIN + 10000);
    vector<int64_t> max_sumr(n, INT64_MIN + 10000);

    max_suml[0] = points[0];
    max_sumr[n - 1] = points[n - 1];

    for (long long i = 1; i < n; i++)
    {
        for (long long j = 0; j < k; j++)
        {
            if (i - moves[j] < 0)
                continue;

            if (max_suml[i] < max_suml[i - moves[j]] + points[i])
                max_suml[i] = max_suml[i - moves[j]] + points[i];
        }
    }

    for (long long i = n - 2; i >= 0; i--)
    {
        for (long long j = 0; j < k; j++)
        {
            if (i + moves[j] >= n)
                continue;

            if (max_sumr[i] < max_sumr[i + moves[j]] + points[i])
                max_sumr[i] = max_sumr[i + moves[j]] + points[i];
        }
    }

    // for (size_t i = 0; i < n; i++)
    // {
    //     if (max_suml[i] > -500)
    //         cout << setw(4) << max_suml[i] << " ";
    //     else
    //         cout << setw(4)<< " - ";
    // }
    // cout << endl;

    // for (size_t i = 0; i < n; i++)
    // {
    //     if (max_sumr[i] > -500)
    //         cout<< setw(4) << max_sumr[i] << " ";
    //     else
    //         cout<< setw(4) << " - ";
    // }
    // cout << endl;

    int64_t max_res = INT64_MIN;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i+1;  j< n; j++)
        {   
            if(max_suml[i] == INT64_MIN + 10000 && max_sumr[j] < 0)
                continue;
            if(max_suml[i] + max_sumr[j] > max_res)

                max_res = max_suml[i] + max_sumr[j];
        }
        
    }
    cout << max_res<<endl;

    return 0;
}
