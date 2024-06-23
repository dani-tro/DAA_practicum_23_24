#include <iostream>
#include <iomanip>

using namespace std;

void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

#define MAXN 110
#define MAXS 10100

int N, a, b;

int A[MAXN];

long long counter;

long long dp[MAXS];

long long calc(int idx)
{
    if(idx > N) return 0;

    long long ans = A[idx];
    for(int i = 1; i < N - idx; i++)
    {
        if(!dp[ans] && ans >= a && ans <= b) {
            counter++;
            dp[ans] = 1;
        }
        ans += calc(idx + i);
    }

    return ans;
}

int main()
{
    fast_IO();

    cin >> N >> a >> b;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    calc(0);

    cout << counter << endl;

    return 0;
}