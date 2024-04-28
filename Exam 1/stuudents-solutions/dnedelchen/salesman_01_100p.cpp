#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 1024
using namespace std;
typedef long long ll;
int n;
double m;

struct spice
{
    double quantity, cost;
    int idx;
    bool operator <(const spice &other) const
    {
        return cost > other.cost;
    }
};

spice spices[MAXN];
double taken[MAXN];


void input()
{
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> spices[i].quantity >> spices[i].cost;
        spices[i].idx = i;
    }
}

void solve()
{
    sort(spices, spices + n);
    int i = 0;
    double gain = 0;
    while (m >= 0.0 && i < n)
    {
        if (m >= spices[i].quantity)
        {
            taken[spices[i].idx] = spices[i].quantity;
            m -= spices[i].quantity;
//            cout << "* " << spices[i].quantity << " " << spices[i].cost << " " << spices[i].quantity * spices[i].cost << endl;
            gain += spices[i].quantity * spices[i].cost;
        }
        else
        {
//            cout << "+ " << m << " " << spices[i].cost << " " << m * spices[i].cost << endl;
            taken[spices[i].idx] = m;
            gain += m * spices[i].cost;
            m -= spices[i].quantity;
            break;
        }

        ++i;
    }

    cout << fixed << setprecision(2) << gain << endl;
    for (int i = 0; i < n; ++i)
        cout << fixed << setprecision(3) << taken[i] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();


    return 0;
}
/**
50
3
10.000 6.00
30.000 4.00
20.000 5.00


100
1
10.250 6.58
*/
