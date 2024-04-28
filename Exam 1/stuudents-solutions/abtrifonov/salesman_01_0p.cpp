#include <bits/stdc++.h>

using namespace std;

double n;
int m;

struct Product
{
    double amount, price;
    Product(double amm, double pr) : amount(amm), price(pr) {}

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

    for (Product &x : vec)
    {
        cout << x.amount << " " << x.price << endl;
    }

    double result{};
    int index = m - 1;
    vector<double> output;

    while (index >= 0 && n > 0)
    {
        if (vec[index].amount <= n)
        {
            n -= vec[index].amount;
            result += vec[index].amount * vec[index].price;
            output.push_back(vec[index].amount);
            if (n == 0)
                break;
        }
        else
        {
            result += n * vec[index].price;
            output.push_back(n);
            n = 0;
        }
        index--;
    }

    cout << fixed << setprecision(2) << result << endl;
    for (auto &x : output)
    {
        cout << fixed << setprecision(3) << x << endl;
    }

    return 0;
};