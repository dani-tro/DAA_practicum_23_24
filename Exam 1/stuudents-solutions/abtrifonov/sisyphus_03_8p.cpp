#include <bits/stdc++.h>

using namespace std;
long long n, m, k, l, r;

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

int calculate(vector<Point> a)
{
    int result{};
    for (auto &x : a)
    {
        result += (x.value * x.passed);
    }
    return result;
}

void func()
{
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
            break;
        }
        else
        {
            k -= vec[lastIdx].value;
            vec[lastIdx].value = 0;
        }
        lastIdx--;
    }

    if (lastIdx == 0)
    {
        cout << 0 << endl;
        return;
    }
    else
    {

        sort(vec.begin(), vec.end(), [](Point a, Point b)
             { return a.idx < b.idx; });

        cout << calculate(vec) << endl;
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    func();

    return 0;
}