#include <bits/stdc++.h>
using namespace std;

void checkNoInput() {
    string K;
    assert(!getline(cin, K));
}

string readLine() {
    string K;
    assert(getline(cin, K));
    return K;
}

long long toLong(const string& K) {
    if (K == "+" || K == "?") return 0 - (K == "+");
    assert(K.size());
    assert(K.size() <= 19);
    long long ans = 0;
    bool sign = 1;
    for (char c: K) {
        assert(isdigit(c) || (sign && c == '-'));
        if (c == '-') sign = 0;
        else ans = 10*ans+c-'0';
    }
    if (!sign) ans = -ans;
    return ans;
}

vector<long long> ans;
vector<string> v;
void numbersOnLine() {
    string K = readLine();
    v.resize(1);
    for (char c: K) {
        if (c == ' ') v.push_back("");
        else v.back().push_back(c);
    }
    ans.clear();
    for (string& K: v) ans.push_back(toLong(K));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<bool> groups(8, true);
    vector<int> all;

    numbersOnLine();
    vector<long long> first = ans;
    assert(first.size() == 2);

    long long N = first[0];
    long long K = first[1];
    
    assert(1 <= N && N <= 10000000);
    assert(1 <= K && K <= 1000000000000000000);
    if (N >= 101) groups[2] = false;
    if (N >= 501) groups[3] = false;
    if (N >= 5001) groups[4] = false;
    if (N >= 500001 || K != 1) groups[5] = false;
    if (N >= 500001) groups[6] = false;

    numbersOnLine();
    first = ans;
    assert(first.size() == N);
    for (int i = 0 ; i <= N-1 ; ++i) 
    {
        assert(0 <= first[i] && first[i] <= 1000);
    }

    std::cout << "OK\n";
    for (int i = 1 ; i <= groups.size()-1 ; ++i)
    {
        if (groups[i]) std::cout << i << ' ';
    }
    std::cout << '\n';
    
    return 0;
}