#include <bits/stdc++.h>
using namespace std;

#define MAXN 110

int m, n;
double c[MAXN], s;

struct item
{
    double kg;
    double price;
    int idx;
};

bool cmp(const item& it1, const item& it2)
{
    return it1.price > it2.price;
}

item items[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> items[i].kg >> items[i].price;
        items[i].idx = i;
    }

    int i = 0;

    sort(items + 1, items + n + 1, cmp); 

    for (int i = 1; i <= n; i++)
    {
        if (items[i].kg < m)
        {
            m -= items[i].kg;
            s += items[i].kg * items[i].price;
            c[items[i].idx] = items[i].kg;
        }
        else
        {
            s += m * items[i].price;
            c[items[i].idx] = m;
            break;
        }
    }
    
    cout << fixed << setprecision(2) << s << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << fixed << setprecision(3) << c[i] << endl;
    }
    
    return 0;
}