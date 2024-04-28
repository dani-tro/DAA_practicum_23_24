#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

int m;
int n;

std::vector<std::vector<double>> products;

void input()
{
    std::cin >> m >> n;
    for (size_t i = 0; i < n; i++)
    {
        double weight, price;
        std::cin >> weight >> price;
        std::vector<double> row;
        row.push_back(weight);
        row.push_back(price);
        products.push_back(row);
    }
}

double tot()
{
    double tot = 0;
    for (size_t i = 0; i < n; i++)
    {
        tot += products[i][0] * products[i][1];
    }
    return tot;
}

void print()
{
    std::cout << std::fixed << std::setprecision(2) << tot() << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        std::cout << std::fixed << std::setprecision(3) << products[i][0] << std::endl;
    }
}

void solve()
{
    std::sort(products.begin(), products.end(), [](const auto &a, const auto &b) {
        return a[0] < b[0];
    });

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += products[i][0];
    }

    if (m < sum)
    {
        products[n - 1][0] -= sum - m;
    }
    print();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    input();
    solve();
    return 0;
}