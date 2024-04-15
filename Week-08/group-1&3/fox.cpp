# include <bits/stdc++.h>
using namespace std;
vector <int> g[26];
string s[105];
int in[26];
void add_edge(string a, string b){
    int i;
    for (i = 0; i < min(a.size(), b.size()); i++){
        if (a[i] != b[i]){
            g[a[i] - 'a'].push_back(b[i]-'a');
            in[b[i]-'a']++;
            return ;
        }
    }
    if (b.size() < a.size()){
        cout << "Impossible" << endl;
        exit(0);
    }
}
vector <int> ans;
int main(){

    int n;
    cin >> n;
    int i, h;
    for (i = 1; i <= n; i++){
        cin >> s[i];
    }

    for (i = 1; i < n; i++){
        add_edge(s[i], s[i+1]);
    }
    queue <int> q;
    for (i = 0; i < 26; i++){
        if (in[i] == 0) q.push(i);
    }

    while (!q.empty()){
        int curr = q.front(); q.pop();
        ans.push_back(curr);
        for (auto u : g[curr]){
            in[u]--;
            if(in[u] == 0) q.push(u);
        }
    }

    if (ans.size() == 26) {
            for (auto x : ans){
                cout << char(x + 'a');
            }

    } else cout << "Impossible\n";
}
