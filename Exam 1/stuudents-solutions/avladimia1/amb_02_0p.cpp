#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <tuple>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> arr(n-1);
    for (auto& el : arr) cin >> el;

    cout << n / k;

    return 0;
}