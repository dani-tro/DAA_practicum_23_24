#include <bits/stdc++.h>
using namespace std;

struct Point{
    long long x;
    long long type;
    bool operator<(Point &other){
        if(this->x != other.x){
            return this->x < other.x;
        }
        return this->type > other.type;
    }
};

vector<long long> weights;
vector<Point> points;
priority_queue<pair<long long,long long>> toreduce; //nai golemi po purvi index otgore, ako sa ravni nai golemi po vtori

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
    for(long long i=1;i<=n;i++){
        long long curweight;
        cin >> curweight;
        weights.push_back(curweight);
    }
    for(long long i=1;i<=2*m;i++){
        long long pointx;
        cin >> pointx;
        if(i%2 != 0){
            points.push_back({pointx,1});
        }else{
            points.push_back({pointx,-1});
        }
    }
    sort(points.begin(),points.end());
    long long curopen=0;
    long long totaldifficulty = 0;
    for(long long j=1, i=1;j<= n;j++){
        while(points[i].x == j && points[i].type == 1){
            curopen = curopen + points[i].type;
            i++;
        }
        totaldifficulty = totaldifficulty + curopen*weights[j];
        toreduce.push({curopen,j});
        while(points[i].x == j && points[i].type == -1){
            curopen = curopen + points[i].type;
            i++;
        }//1 +3 + 5*2 + 4 =18 -2*2 = 14
    }
    while(!toreduce.empty() && k > 0){ //first is curopen second is index in weights
        if(weights[toreduce.top().second] >= k){
            totaldifficulty = totaldifficulty - toreduce.top().first*k;
            //cout << toreduce.top().first << " " <<weights[toreduce.top().first];
            k =0;
            break;
        }else{
            totaldifficulty = totaldifficulty - toreduce.top().first*weights[toreduce.top().second];
            k = k - weights[toreduce.top().second];
            toreduce.pop();
        }
    }
    cout << totaldifficulty;
    return 0; 
}
