#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

void print_queue(priority_queue<pair<double, pair<double, double>>>& q) {
    while (!q.empty()) {
        std::cout << fixed << setprecision(3) << q.top().second.first << " " << fixed << setprecision(2) << q.top().second.second << endl;
        q.pop();
    }
    std::cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double m;
    int n;
    cin >> m >> n;

    pair<double, pair<double, double>> product;
    priority_queue<pair<double, pair<double, double>>> storage;

    for (int i = 0; i < n; i++)
    {
        cin >> product.second.first >> product.first;
        product.second.second = i;
        storage.push(product);

    }
    
    double remainingCapacity = m;
    double totalSold = 0;

    //now first is id
    priority_queue<pair<double, pair<double, double>>> backlog;

    while (remainingCapacity > 0 && !storage.empty()) {
        if (remainingCapacity >= storage.top().second.first) {
            totalSold += storage.top().first * storage.top().second.first;

            swap(storage.top().second.second, storage.top().first);
            backlog.push(storage.top());
            storage.pop();
        }

        else {
            pair<double, pair<double, double>> newVal;
            newVal.second.first = storage.top().second.first - remainingCapacity;
            newVal.first = storage.top().second.second;
            newVal.second.second = storage.top().first;
            
            totalSold += storage.top().first;
            backlog.push(newVal);
            storage.pop();

        }
    }

    cout << fixed << setprecision(2) << totalSold << endl;

    print_queue(backlog);

    return 0;
}