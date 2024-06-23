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

long long dp[MAXS];

int main()
{
    fast_IO();

    cin >> N >> a >> b;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long counter = 0;
    long long sum = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!dp[sum] && sum >= a && sum <= b) {
                counter++;
                dp[sum] = 1;
            }

            if(sum + A[i+j] <= b) sum += A[i+j]; 
        }
        sum = 0;
    }

    cout << counter << endl;

    return 0;
}