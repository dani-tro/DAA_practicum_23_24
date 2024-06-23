#include <iostream>
#include <vector>
#include <set>
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,a,b;
    cin >> n >> a >> b;
    vector<int> xs(n);
    for (auto& x : xs)
        cin >> x;
    set<int> sums;

    for (auto& x : xs) {
        for (auto& sum : sums) {
            if (x + sum <= b) {
                sums.insert(x+sum);
            }
        }
        if (x <= b) {
            sums.insert(x);
        }
    }
    set<int> sums2;
    for (auto& sum : sums) {
        if (sum >= a) {
            sums2.insert(sum);
        }
    }
    cout << sums2.size() << endl;

}