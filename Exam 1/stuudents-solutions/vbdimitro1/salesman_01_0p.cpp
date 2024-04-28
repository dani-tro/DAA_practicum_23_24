#include <vector>
#include <iostream>
using namespace std;
void quicksortmod(vector<double>& arr, vector<double>& pt, vector<int> ind)
{
    if (arr.size() <= 1)
        return;

    unsigned size = arr.size();

    double pivot = arr[0];

    vector<double> smaller, bigger, equal;
    vector<double> smallerpt, biggerpt, equalpt;
    vector<int> smallerind, biggerind, equalind;

    for (unsigned i = 0; i < size; i++)
    {
        if (arr[i] > pivot)
        {
            bigger.push_back(arr[i]);
            biggerpt.push_back(pt[i]);
            biggerind.push_back(ind[i]);
        }
        else if (arr[i] < pivot)
        {
            smaller.push_back(arr[i]);
            smallerpt.push_back(pt[i]);
            smallerind.push_back(ind[i]);
        }
        else
        {
            equal.push_back(arr[i]);
            equalpt.push_back(pt[i]);
            equalind.push_back(ind[i]);
        }
    }

    quicksortmod(smaller, smallerpt, smallerind);
    quicksortmod(bigger, biggerpt, biggerind);

    arr = bigger;
    pt = biggerpt;
    ind = biggerind;

    unsigned eqSize = equal.size();
    unsigned smSize = smaller.size();
    for (unsigned i = 0; i < eqSize; i++)
    {
        arr.push_back(equal[i]);
        pt.push_back(equalpt[i]);
        ind.push_back(equalind[i]);
    }
    for (unsigned i = 0; i < smSize; i++)
    {
        arr.push_back(smaller[i]);
        pt.push_back(smallerpt[i]);
        ind.push_back(smallerind[i]);
    }

    return;
}

int main()
{
    int m;
    int n;

    cin >> m >> n;

    vector<double> weights;
    vector<double> prices;
    vector<int> indexes;

    for (int i = 0; i < n; i++)
    {
        double w, p;
        cin >> w >> p;

        weights.push_back(w);
        prices.push_back(p);
        indexes.push_back(i);
    }

    quicksortmod(prices, weights, indexes);

    int totalSum = 0;
    double currentWeight = 0;
    double sum = 0;
    vector<double> amounts;

    for (int i = 0; i < n; i++)
    {
        double buyAmount = 0;
        if (weights[i] < m)
        {
            buyAmount = weights[i];
            m -= weights[i];
            sum += weights[i] * prices[i];
        }
        else
        {
            buyAmount = m;
            m = 0;
            sum += weights[i] * prices[i];
        }
        amounts.push_back(buyAmount);
    }


    cout << fixed << setprecision(2) << sum << endl;
    for (int i = 0; i < amounts.size(); i++)
        cout << fixed << setprecision(3) << amounts[indexes[i]] << endl;

    return 0;
}