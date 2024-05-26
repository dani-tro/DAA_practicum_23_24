#include <bits/stdc++.h>
using namespace std;

const long long SIZE = 10'000 + 5;
struct edge {
    int u,v;
    long long w;
    bool operator<(const edge& other)const {
        return this->w > other.w;
    }
};
struct vertex{
    int name;
    int value;
};
vector<vertex> beetles[11];

bool visited[SIZE];

vector<edge> graph[SIZE];
long long total = 0;
int N;
void prim() {
    long long s=0;
    priority_queue<edge> pq;
    for (edge e : graph[s]){
        pq.push(e);
    }
    visited[s] = true;
    while(!pq.empty()) {
        edge curr = pq.top();
        pq.pop();
        if (visited[curr.v])
            continue;
        visited[curr.v] = true;
        for (edge e : graph[curr.v]){
            pq.push(e);
        }
        
        total +=curr.w;
    }   
}
int findClosestElement(vector<vertex>& v, int value) {
    if (v.size() == 0) {
        return -1;
    }
    int l = 0;
    int r = v.size();
    int ans = -1;
    while(l <r) {
        int mid = (l+r)/2;
        if (v[mid].value > value) {
            ans = mid;
            r = mid - 1;
        } else if (v[mid].value == value){
            return mid;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (long long i = 0; i < N;i++){
        int x,y;    
        cin >> x >> y;
        beetles[y].push_back((vertex){i,x});
    } 
    for (long long i = 0; i < 11; i++) {
        sort(beetles[i].begin(),beetles[i].end(),[](vertex v1,vertex v2) {
            return v1.value < v2.value;
        });
    }
    
    for (long long i = 0; i <=10;i++){
        vector<vertex>& curr = beetles[i];
        for (long long j = 0;j<curr.size() - 1;j++) {
            long long cost = (curr[j].value - curr[j+1].value) * (curr[j].value - curr[j+1].value);
            graph[curr[j].name].push_back({curr[j].name,curr[j+1].name,cost});
            graph[curr[j + 1].name].push_back({curr[j + 1].name,curr[j].name,cost});
        }
        
       for (int j =0;j<curr.size();j++) {
            vertex currVertex = curr[j];
            for (int k=0;k<=10;k++) {
                if (k==i) continue;
                int index = findClosestElement(beetles[k],currVertex.value);
                if (index == -1) continue;
                int first = index - 1;
                int second = index;
                int third = index + 1;
                if (first >=0) {
                    graph[currVertex.name].push_back((edge){currVertex.name,beetles[j][first].name,
                    (currVertex.value - beetles[j][first].value) *  (currVertex.value - beetles[j][first].value)
                    + (j-i) * (j-i)});
                     graph[beetles[j][first].name].push_back((edge){beetles[j][first].name,currVertex.name,
                    (currVertex.value - beetles[j][first].value) *  (currVertex.value - beetles[j][first].value)
                    + (j-i) * (j-i)});
                } 
                graph[currVertex.name].push_back((edge){currVertex.name,beetles[j][second].name,
                    (currVertex.value - beetles[j][second].value) *  (currVertex.value - beetles[j][second].value)
                    + (j-i) * (j-i)});
                     graph[beetles[j][second].name].push_back((edge){beetles[j][second].name,currVertex.name,
                    (currVertex.value - beetles[j][second].value) *  (currVertex.value - beetles[j][second].value)
                    + (j-i) * (j-i)});
                if (third <beetles[j].size()) {
                    graph[currVertex.name].push_back((edge){currVertex.name,beetles[j][third].name,
                    (currVertex.value - beetles[j][third].value) *  (currVertex.value - beetles[j][third].value)
                    + (j-i) * (j-i)});
                     graph[beetles[j][third].name].push_back((edge){beetles[j][third].name,currVertex.name,
                    (currVertex.value - beetles[j][third].value) *  (currVertex.value - beetles[j][third].value)
                    + (j-i) * (j-i)});
                }
            }
       }
        prim();
        cout << total;

       
        
    }
    
    
    // for (long long i = 0; i < N; i++){
    //     pair<long long,short> curr = beetles[i];
    //     for (long long j = i+1; j < N; j++) {
    //         pair<long long,short> curr1=beetles[j];
    //         long long cost = (curr.first - curr1.first)*(curr.first - curr1.first) +
    //                         (curr.second - curr1.second) * (curr.second - curr1.second);
    //     graph[i].push_back((edge){i,j,cost});
    //     graph[j].push_back((edge){j,i,cost});
    //     }
    // }
    prim();
    cout << total;

}