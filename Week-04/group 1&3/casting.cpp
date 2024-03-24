# include <bits/stdc++.h>
using namespace std;
long long n, m;
struct singer{
    long long arrival, duration;
};
singer s[10005];
long long studios[10005];
bool cmp (singer x, singer y){
    if (x.arrival == y.arrival) return x.duration > y.duration;
    return x.arrival < y.arrival;
}
long long get_studio(int t){
    long long min = 0;
    for (long long i = 0; i < n; i++){
        if (studios[i] <= t) return i;
        if (studios[i] < studios[min]) min = i;
    }
    return min;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long i;
    cin >> n >> m;
    for (i = 0; i < m; i++)
        cin >> s[i].arrival >> s[i].duration;
    sort(s, s+m, cmp);
    for (i = 0; i < m; i++){
        long long ids = get_studio(s[i].arrival);
        if (studios[ids] < s[i].arrival)
            studios[ids] = s[i].arrival + s[i].duration;
        else
            studios[ids] += s[i].duration;
    }

    long long max = 0;
    for (long long i = 0; i < n; i++){
        if (studios[i] >= studios[max]) max = i;
    }
    cout << studios[max] << " " << max+1 << endl;
}
