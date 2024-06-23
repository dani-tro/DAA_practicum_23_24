#include <iostream>
#include <vector>
using namespace std;

const int modul = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S;
    cin >> S;

    if(S == 0){
        cout << 0;
        return 0;
    }

    vector<int> gore(S + 1, 1);
    vector<int> dolu(S + 1, 1);

    for (int i = 2; i <= S; ++i) {
        for (int j = 1; j < i; ++j) {
            if (j < i - 1) {
                gore[i] = (gore[i] + dolu[j]) % modul;
            }
            if (j > 1) {
                dolu[i] = (dolu[i] + gore[j]) % modul;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= S; ++i) {
        result = (result + gore[i]) % modul;
        result = (result + dolu[i]) % modul;
    }

    cout << result;
    
    return 0;
}
