#include <bits/stdc++.h>
using namespace std;

struct good
{
    double amount;
    double price;
    int ind;

    bool operator<(const good& other)
    {
        return this->price > other.price || (this->price == other.price && this->price < other.price);
    }
};

int n, m;
good arr[105];
double buffer[105]{0};


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> m;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].amount >> arr[i].price;
        arr[i].ind = i;
    }

    sort(arr,arr+n);

    double sum = 0;

    for(int i = 0; i < n && m > 0; i++)
    {
        if(arr[i].amount*arr[i].price < m*arr[i].price)
        {
            sum+=arr[i].amount*arr[i].price;
            m -= arr[i].amount;
            buffer[arr[i].ind] += arr[i].amount;
        }
        else
        {
            sum+=m*arr[i].price;
            buffer[arr[i].ind] += m;
            m -= m;
        }
    }

    cout <<  fixed << setprecision(2) << sum << endl;

    for(int i = 0; i < n; i++)
    {
        cout <<  fixed << setprecision(3) << buffer[i] << endl;
    }

    return 0;

}