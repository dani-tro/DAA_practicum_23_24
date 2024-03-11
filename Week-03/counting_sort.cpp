// O(n+maxA)

# include <bits/stdc++.h>
using namespace std;
const int MAXA = 1024;
int cnt[MAXA];
int main() {
    ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


    int n;
    cin >> n;
    int i, x;
    for (int i = 0; i < n; i++){
        cin >> x;
        cnt[x] ++;
    }
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < cnt[i]; j++)
            cout << i << " ";
    }
    cout << endl;

}
