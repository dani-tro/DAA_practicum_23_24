#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
#include <deque>
#include <queue>
#include <stack>

using namespace std;


// Task 4

struct product
{
    double a = 0.000;
    double b = 0.00;
    int index = -1;
};

double m;
int n;
vector<product> arr;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> m >> n;

    for (int i = 0; i < n; ++i)
    {
        product temp;
        cin >> temp.a >> temp.b;

        int tempA = (double)temp.a * 1000;
        temp.a = (double)tempA / 1000;

        int tempB = (double)temp.b * 100;
        temp.b = (double)tempB / 100;

        temp.index = i;
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end(), [](product p1, product p2) {return p1.b > p2.b; });

    double cur = 0;
    double lv = 0;
    int i = 0;
    for (; i < n; ++i)
    {
        if (cur == m)
        {
            break;
        }
        if (arr[i].a <= m - cur)
        {
            cur += arr[i].a;
            lv += arr[i].a * arr[i].b;
        }
        else
        {
            int temp = m - cur;
            cur += temp;
            lv += temp * arr[i].b;
            arr[i].a = temp;
        }
    }
    for (; i < n; ++i)
    {
        arr[i].a = 0;
    }

    sort(arr.begin(), arr.end(), [](product p1, product p2) {return p1.index < p2.index; });

    double temp1 = lv - (int)lv;
    int temp2 = (double)temp1 * 100;
    if(temp2 == 0) cout << (int)lv << '.' << "00" << '\n';
    else if(temp2 < 10 && temp2 > 0) cout << (int)lv << '.' << '0' << temp2 << '\n';
    else cout << (int)lv << '.' << temp2 << '\n';

    //cout << fixed << setprecision(2) << lv << '\n';
    for (int j = 0; j < n; ++j)
    {
        //cout << arr[j].a << '\n';
        //cout << fixed << setprecision(3) << arr[j].a << '\n';

        double temp1 = arr[j].a - (int)arr[j].a;
        int temp2 = (double)temp1 * 1000;
        if (temp2 == 0) cout << (int)arr[j].a << '.' << "000" << '\n';
        else if (temp2 < 100 && temp2 >= 10) cout << (int)arr[j].a << '.' << '0' << temp2 << '\n';
        else if (temp2 < 10 && temp2 > 0) cout << (int)arr[j].a << '.' << "00" << temp2 << '\n';
        else cout << (int)arr[j].a << '.' << temp2 << '\n';
    }

}





// Task 3 - ???
/*

long long n;
long long m;
long long k;
vector<point> arrD;

struct point
{
    long long val;
    int beg = -2; // +1 beg, -1 end
    int goOver = 0; // +1 beg, -1 end
    int end = -2; // +1 beg, -1 end
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> n >> m >> k;
    for (long long i = 0; i < n; ++i)
    {
        point temp;
        cin >> temp.val;
        arrD.push_back(temp);
    }

    for (long long i = 0; i < m; ++i)
    {
        long long temp1, temp2;
        cin >> temp1 >> temp2;
        temp1--;
        temp2--;
        arrD[temp1].beg = 1;
        arrD[temp1].goOver = 1;
        arrD[temp2].beg = -1;
        arrD[temp2].goOver = 1;
    }

    long long maxUsed = 0;
    long long index = 0;
    long long check = 0;
    for (long long i = 0; i < n; ++i)
    {
        if (arrD[i].beg == 1)
        {
            ++check;
        }
        else if (arrD[i].end == -1)
        {
            if (maxUsed < check)
            {
                maxUsed = check;
                index = i;
            }
            --check;
        }
        else
        {
            if (check > 0)
            {
                arrD[i].goOver = check;
            }
        }
    }
    
    if (arrD[index] >= k)
    {
        arrD[index].val -= k;
    }

    while (k > 0)
    {
        for (long long i = 0; i < n; ++i)
        {
            if (arrD[i].goOver == maxUsed)
            {
                arrD[i].goOver--;
            }
        }

    }
}
*/





// Task 1 - 50
/*
int n;
int k;
std::vector<int> arr;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);   

    cin >> n >> k;
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), [](int a, int b) {return a > b; });

    int maxcount = 0;
    int count = 1;
    int res = 0;
    for (int i = 0; i < n - count + 1; ++i)
    {
        while (i + count - 1 < n)
        {
            res = arr[i] - arr[i + count - 1];
            if (res <= k)
            {
                ++count;
            }
            else
            {
                --count;
                break;
            }
        }
        if (count > maxcount) maxcount = count;
    }

    cout << maxcount << '\n';
};

//10 4
// 5 9 3 1 2 7 8 9 5 8

// 9 9 8 8 7 5 5 3 2 1

*/