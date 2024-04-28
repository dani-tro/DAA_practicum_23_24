#include <iostream>>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

const int MAX_SIZE = 100000;

long long A[MAX_SIZE];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k;
    cin >> n >> k;
    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    int max = 0;
    int cnt;
    int start, end;
    start = 0;
    end = 0;
    int diff;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] - A[start] > k) {
            while (A[i] - A[start] > k) {
                start++;
            }
        }
        if (i - start + 1 > max) {
            max = i - start + 1;
        }
    }

    cout << max;
}