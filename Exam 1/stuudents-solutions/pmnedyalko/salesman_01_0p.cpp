#include <bits/stdc++.h>

const int MAX_SIZE = 128;
int n, m;
double currentCap, totalPrice;
double cap[MAX_SIZE];
std::vector<std::pair<double, double>> v;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>m>>n;
    double a,b;
    for (size_t i = 0; i < n; i++) {
        std::cin>>a>>b;
        v.push_back({a,b});
    }

    std::sort(v.begin(), v.end());

    for (size_t i = 0; i < v.size(); i++) {
        if(currentCap + v[i].first <= m) {
            currentCap += v[i].first;
            totalPrice += v[i].first * v[i].second;
            cap[i] += v[i].first;
        } else {
            double last = m - currentCap;
            totalPrice += last * v[i].second;
            cap[i] += last;
        }
    }
    
    std::cout << std::fixed << std::setprecision(2) << totalPrice << std::endl;
    for (size_t i = 0; i < n; i++) {
        std::cout << std::fixed << std::setprecision(3) << cap[i] << std::endl;
    }
    

}