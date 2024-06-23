#include <bits/stdc++.h>

//#define MAX 10000000;

using namespace std;

int n;
int cnt = 0;
bool bb = false;
long sum = 0;
long result = 0;
long k;
int value;
queue<int> pairs;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> value;
        if (i > 0) {
            result += sum * value;
        }
        sum += value;
        //cout << result << endl;
        pairs.push(value);
        if (result > k) {
            cout << i << endl;
            if (bb) {
                cnt *= 2;
            }
            cnt += 1;
            result -= pairs.front() * sum;
            sum -= pairs.front();
            pairs.pop();
            bb = true;;
        }
    }
    cout << cnt;
}