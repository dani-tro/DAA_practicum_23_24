#include <bits/stdc++.h>

#define N 20005

std::vector<int> adj[N];
std::unordered_set<int> flowers;
int d[N];
bool visited[N];
int k, f, x;

bool top() {
    std::queue<int> pq;
    int count = 0;
    for (auto fl : flowers) {
        if (d[fl] == 0) {
            pq.push(-fl);
        }
    }

    while (!pq.empty()) {
        int flower = -(pq.front());
        pq.pop();
        if (visited[flower]) continue;
        visited[flower] = true;
        count++;
        for (auto elem : adj[flower]) {
            d[elem]--;
            if (d[elem] == 0) {
                pq.push(-elem);
            }
        }
        if (count == flowers.size()) break;
    }
    return count == flowers.size();
}



int main() {
    std::cin >> k;
    std::fill(d, d + N - 1, 0);
    int s;
    for (int i = 0; i < k; i++) {
        int last = 0;
        std::cin >> f;
        for (int j = 0; j < f; j++) {
            std::cin >> x;
            flowers.insert(x);
            if (last != 0) {
                adj[last].push_back(x);
                d[x]++;
            }
            last = x;
        }
        s = last;
    }
    std::cout << top();
}