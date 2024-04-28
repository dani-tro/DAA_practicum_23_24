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

struct intervalshit{
    int value;
    bool closing;
};
//vector<point_intersects> counter(100005);
vector<intervalshit> intervals;
void input(){
    cin >> n >> m >> k;
    int p, l , r;
    points.resize(n);
    for(int i = 0; i < n; i++){
        cin >> p;
        points[i]={p, 0};
    }
    intervals.resize(2*m);
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        for(int g = l-1; g < r; g++){
            points[g].ins++;
        }
       // intervals[2*i] = {l , false};
       // intervals[2*i+1] = {r, true};
    }

}

int solve(){
//    sort(intervals.begin(), intervals.end(), []
//    (intervalshit& i1, intervalshit &i2){
//        return i1.value < i2.value || (i1.value == i2.value && !i1.closing);
//    });
//
//    int currOpen = 0;
//    int index = intervals[0].value;
//    for(int i = 0; i < 2*m; i++){
//        if(!intervals[i].closing){
//
//        }
//    }
    sort(points.begin(), points.end(), []
    (point_intersects& p1, point_intersects& p2){
        return p1.ins > p2.ins;
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
