#include <bits/stdc++.h>
using namespace std;

struct item
{
    int order;
    double taken;
    double value;
    double weight;
};

void solve(double capacity, vector<item> items)
{
    // sort the items by value and weight
    sort(items.begin(), items.end(), [](item a, item b)
    {
         return a.value * b.weight > b.value * a.weight;
    });

    // solve the knapsack problem using greedy approach
    double total = 0.0;
    for (int i = 0; i < items.size() && capacity > 0; i++)
    {
        if (capacity >= items[i].weight)
        {
            // take full weight of the item
            items[i].taken = items[i].weight;
            total += items[i].value;
            capacity -= items[i].taken;
        }
        else
        {
            // take a fraction of the item
            double fraction = capacity / items[i].weight;
            items[i].taken = fraction * items[i].weight;
            total += fraction * items[i].value;
            capacity = 0;
        }
    }

    // sort the items by order
    sort(items.begin(), items.end(), [](item a, item b)
    {
        return a.order < b.order;
    });

    // print the output
    cout << fixed << setprecision(2) << total << endl;
    for (int i = 0; i < items.size(); i++)
    {
        cout << fixed << setprecision(3) << items[i].taken << endl;
    }
    cout << endl;
}

int main()
{
    double capacity;
    cin >> capacity;

    int n;
    cin >> n;
    vector<item> items(n);
    for (int i = 0; i < n; i++)
    {
        items[i].order = i;
        items[i].taken = 0.0;
        cin >> items[i].weight >> items[i].value;
        items[i].value *= items[i].weight;
    }
    solve(capacity, items);
    cin >> capacity;
    return 0;
}
