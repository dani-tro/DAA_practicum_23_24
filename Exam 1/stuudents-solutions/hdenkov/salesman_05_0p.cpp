#include <bits/stdc++.h>
using namespace std;

#define MAX 110
#define eps 1e-6

double quantities[MAX];

struct spice
{
    size_t idx;
    double quant;
    double price;

    spice(size_t _idx, double _quant, double _price) : idx(_idx), quant(_quant), price(_price) {}

    bool operator<(const spice &other)
    {
        return price < other.price;
    }
};

int maxKg;
int n;
vector<spice> spices;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> maxKg >> n;
    size_t i;
    double a, b;
    for (i = 0; i < n; ++i)
    {
        cin >> a >> b;

        spices.push_back({i, -a, -b});
    }

    sort(spices.begin(), spices.end());

    i = 0;
    double winnings = 0, maxToSell = 0;

    while (maxKg > 0 && i < n)
    {
        maxToSell = fmin((double)maxKg, -spices[i].quant);
        winnings += maxToSell * -spices[i].price;
        quantities[spices[i].idx] = maxToSell;
        maxKg -= maxToSell;
        i++;
    }

    cout << fixed << setprecision(2) << winnings << endl;
    for (i = 0; i < n; ++i)
    {
        cout << fixed << setprecision(3) << quantities[spices[i].idx] << endl;
    }
}
