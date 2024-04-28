#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
long long n, m, k;
struct point_intersects{
    int point;
    int ins=0;
};
vector<point_intersects> points;
void input(){
    cin >> n >> m >> k;
    int p, l , r;
    points.resize(n);
    for(int i = 0; i < n; i++){
        cin >> p;
        points[i]={p, 0};
    }
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        for(int g = l-1; g < r; g++){
            points[g].ins++;
        }
    }

}

long long solve(){

    sort(points.begin(), points.end(), []
            (point_intersects& p1, point_intersects& p2){
        return p1.ins > p2.ins || (p1.ins == p2.ins && p1.point < p2.point);
    });
    int idx = 0;
    while(k > 0 && idx < points.size()){
        if(points[idx].point > 0){
            points[idx].point--;
            k--;
        } else {
            idx++;
        }
    }
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += points[i].ins * points[i].point;
    }
    return sum;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    cout << solve();
    return 0;
}
