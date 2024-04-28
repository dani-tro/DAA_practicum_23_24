#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100005;
const int MAX_M = 10004;
int a[MAX_N];
int b[2][MAX_M];
pair<int, int> freq[MAX_N];//first = freq, second = ind

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i, j;
    unsigned long long k;
    cin >> n >> m >> k;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        freq[i].first = 0;
        freq[i].second = i;
    }

    int l, r;
    for (i = 0; i < m; ++i) {
        cin >> l >> r;
        b[0][i] = l;
        b[1][i] = r;
        for (j = l; j <= r; ++j) {
            freq[j].first += 1;
        }
    }

    sort(freq + 1, freq + n + 1);

    /*for (i = 0; i < n; ++i) {
        cout << freq[i].second << " - " << freq[i].first;
    }*/

    int curr = n;

    while (k > 0 && curr >= 0) {
        int ind = freq[curr].second;
        while (a[ind] >= 1 && k > 0) {
            a[ind] -= 1;
            --k;
        }
        --curr;
    }

    double sum = 0;

    for (i = 0; i < m; ++i) {
        for (j = b[0][i]; j <= b[1][i]; ++j) {
            sum += a[j];
        }
    }

    cout << sum;
}