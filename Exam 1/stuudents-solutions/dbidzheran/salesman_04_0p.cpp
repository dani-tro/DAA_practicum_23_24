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
    int check = (int)((double)temp1 * 1000) % 10;
    if (check >= 5) temp2++;
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
        int check = (int)((double)temp1 * 1000) % 10;
        if (check >= 3) temp2++;
        if (temp2 == 0) cout << (int)arr[j].a << '.' << "000" << '\n';
        else if (temp2 < 100 && temp2 >= 10) cout << (int)arr[j].a << '.' << '0' << temp2 << '\n';
        else if (temp2 < 10 && temp2 > 0) cout << (int)arr[j].a << '.' << "00" << temp2 << '\n';
        else cout << (int)arr[j].a << '.' << temp2 << '\n';
    }

}
