#include <bits/stdc++.h>

using namespace std;

double n;
int m;

struct Product
{
    double amount, price, taken;
    Product(double amm, double pr) : amount(amm), price(pr) {
        taken = 0;
    }

    bool operator<(const Product &other)
    {
        if (price != other.price)
        {
            return price < other.price;
        }
        return amount < other.amount;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    double a, b;
    vector<Product> vec;

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        Product temp(a, b);
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    double result{};
    int index = m - 1;
    vector<double> output;

    while (index >= 0 && n > 0)
    {
        if (vec[index].amount <= n)
        {
            n -= vec[index].amount;
            result += vec[index].amount * vec[index].price;
            vec[index].taken = vec[index].amount;
            if (n == 0)
                break;
        }
        else
        {
            result += n * vec[index].price;
            vec[index].taken = n;
            n = 0;
        }
        index--;
    }

    cout << fixed << setprecision(2) << result << endl;
    for (auto &x : vec)
    {
        cout << fixed << setprecision(3) << x.taken << endl;
    }

    return 0;
};