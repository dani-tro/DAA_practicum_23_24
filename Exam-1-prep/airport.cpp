# include <bits/stdc++.h>
using namespace std;
struct airInfo{
    int t;
    int type;
    int nat;
    bool operator< (const airInfo &other){
        if (t != other.t) return t < other.t;
        return type > other.type;
    }
};
const int MAXN = 4e4+5;
const int MAXC = 3005;
airInfo p[MAXN];
int d[MAXC];
int main(){
    int n;
    int a, b, c;
    cin >> n;
    int i;
    for (i = 0; i < 2*n; i++){
        cin >> a >> b >> c;
        p[i].t = a;
        p[i].type = 1;
        p[i].nat = c;
        i++;
        p[i].t = b;
        p[i].type = -1;
        p[i].nat = c;
    }
    sort (p, p+2*n);
    int ans = 0;
    for (i = 0; i < 2*n; i++){
        d[p[i].nat] += p[i].type;
        ans = max(ans, d[p[i].nat]);
    }
    cout << ans << endl;
}
