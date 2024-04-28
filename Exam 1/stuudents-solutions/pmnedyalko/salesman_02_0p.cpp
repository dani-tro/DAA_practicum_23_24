#include <bits/stdc++.h>

const int MAX_SIZE = 128;
int n, m;
double currentCap, totalPrice;
double cap[MAX_SIZE];

struct event {
    double c, p;
    int index;

    bool operator<(const event& other) {
        return p < other.p;
    }
};
std::vector<event> v;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>m>>n;
    double a,b;
    for (int i = 0; i < n; i++) {
        std::cin>>a>>b;
        v.push_back({a,-b,i});
    }

    std::sort(v.begin(), v.end());

    for (size_t i = 0; i < v.size(); i++) {
        if(currentCap + v[i].c <= m) {
            currentCap += v[i].c;
            totalPrice += v[i].c * (-1 * v[i].p);
            cap[v[i].index] += v[i].c;
        } else {
            double last = m - currentCap;
            totalPrice += last * (-1 * v[i].p);
            cap[v[i].index] += last;
        }
    }
    
    std::cout << std::fixed << std::setprecision(2) << totalPrice << std::endl;
    for (size_t i = 0; i < n; i++) {
        std::cout << std::fixed << std::setprecision(3) << cap[i] << std::endl;
    }
    

}