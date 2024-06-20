# include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4+5;
unordered_map <int, string> mp;
string Min(string a, string b)
{
    if (a == "No solution")return b;
    if (b == "No solution") return a;
    if (a.size() == b.size())
    {
        return (a<b ? a : b);
    }
    return (a.size()<b.size() ? a : b);
}
string solve(int s, int p)
{
    if (mp.find(s*MAX+p) != mp.end()) return mp[s*MAX+p];
    if (s == 0)
    {
        if (p == 0) return "";
        return "No solution";
    }
    if (s > p || p > 10*s){
        return "No solution";
    }
    string ans = "No solution";
    for (int i = 1; i <= 9; i++)
    {
        if (s - i >= 0 && p - i*i >= 0)
        {
            string number = solve(s-i, p-i*i);
            if (number != "No solution")
                number += (i+'0');
            ans = Min(ans, number);
        }
    }
    if (ans.size() > 100) ans = "No solution";
    mp[s*MAX+p] = ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int s,p;
        cin >> s >> p;
        cout << solve(s, p) << '\n';
    }

}
