#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int type;
    bool operator<(Point &other){
        if(this->x != other.x){
            return this->x < other.x;
        }
        return this->type > other.type;
    }
};

vector<int> weights;
vector<Point> points;
priority_queue<int> toreduce;

int main(){
    //=
    //+
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,m,k;
    cin >> n >> m >> k;
    weights.push_back(-1); //placeholder on [0]
    points.push_back({-1,0}); // placehodler on[0]
    for(int i=1;i<=n;i++){
        int curweight;
        cin >> curweight;
        weights.push_back(curweight);
    }
    for(int i=1;i<=2*m;i++){
        int pointx;
        cin >> pointx;
        if(i%2 != 0){
            points.push_back({pointx,1});
        }else{
            points.push_back({pointx,-1});
        }
    }
    sort(points.begin(),points.end());
    int maxopen =0;
    int curopen=0;
    int totaldifficulty = 0;
    for(int j=1, i=1;j<= n;j++){
        while(points[i].x == j && points[i].type == 1){
            curopen = curopen + points[i].type;
            i++;
        }
        totaldifficulty = totaldifficulty + curopen*weights[j];
        if(curopen > maxopen){
            maxopen = curopen;
        }
        while(points[i].x == j && points[i].type == -1){
            curopen = curopen + points[i].type;
            i++;
        }
    }
    totaldifficulty = totaldifficulty - maxopen*k;
    cout << totaldifficulty;
    return 0;
}