#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long

int n,k;
vector<int> gr[1000001];
int fr[20001];
int in[20001];
bool exists[20001];
int vertexes;

void topoSort() {
    priority_queue<int> pq;
    int cnt = 0;
    for (int i = 1; i <= 6; i++) {
        if (in[i] == 0 && exists[i]) {
            pq.push(-i);
            cnt++;
        }
    }

    while (!pq.empty()) {
        int node = -(pq.top());
        pq.pop();

        for (auto v : gr[node]) {
            in[v]--;
            if (in[v] == 0) {
                pq.push(-v);
                cnt++;
            }
        }
    }
    cout << (cnt == vertexes) << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    cin >> n;
    int a;
    for(int i = 0; i < n; i++) {
        cin >> k;
        fill(fr, fr + k, 0);
        for(int i = 0; i < k; i++) {
            cin >> fr[i];
            if (exists[fr[i]]) continue;
            exists[fr[i]] = true;
            vertexes++;
        }
        for(int j = 0; j < k - 1; j++) {
            gr[fr[j+1]].push_back(fr[j]);
            in[fr[j]]++;
        }
    }

    topoSort();

    return 0;
}