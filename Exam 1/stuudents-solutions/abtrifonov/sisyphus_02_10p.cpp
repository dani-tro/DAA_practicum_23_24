#include <bits/stdc++.h>

using namespace std;
int n, m, k, l, r;


struct Point
{
    int idx, passed, value;

    Point(int val, int id) : value(val), idx(id)
    {
        passed = 0;
    }

    bool operator<(const Point &other)
    {
        return passed < other.passed;
    }
};

int calculate(vector<Point> a, int l, int r){
    int result = 0;
    for(int i = l - 1; i <= r -1 ; ++i){
        result+=a[i].value;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    vector<Point> vec;

    int temp;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        Point a(temp, i);

        vec.push_back(a);
    }

    vector<int> lefts(m), rights(m);

    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        lefts[i] = l;
        rights[i] = r;
        for (int j = l - 1; j <= r; ++j)
        {
            vec[j].passed++;
        }
    }

    sort(vec.begin(), vec.end());

    int lastIdx = n - 1;

    while (lastIdx > 0 || k > 0)
    {
        if (k < lastIdx)
        {
            vec[lastIdx].value -= k;
            k = 0;
        }
        else
        {
            k -= vec[lastIdx].value;
            vec[lastIdx].value = 0;
        }
        lastIdx--;
    }

    sort(vec.begin(), vec.end(), [](Point a, Point b){return a.idx < b.idx;});

    int result{};

    for(int i = 0; i < m; ++i)
    {
        // cout << lefts[i]  << "  "  << rights[i] << endl;
        result +=calculate(vec, lefts[i], rights[i]);
    }

    cout << result << endl;
    return 0;
};