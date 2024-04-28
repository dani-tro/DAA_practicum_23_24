#include <iostream>
#include<algorithm>
#include <iomanip>
using namespace std;

int getIndex(double v, double* arr, int n) {
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == v) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long m;
    long n;
    std::cin >> m >> n;
    double* kg = new double[n];
    double* pr = new double[n];
    double* prOr = new double[n];
    double* kgToLoad = new double[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> kg[i];
        std::cin >> pr[i];
        prOr[i] = pr[i];
        kgToLoad[i] = 0;
    }
    std::sort(pr, pr + n);
    for (int i = n-1; i >= 0; i--)
    {
        int index = getIndex(pr[i], prOr, n);
        if (m >= kg[index]) {
            m = m - kg[index];
            kgToLoad[index] = kg[index];
        }
        else {
            kgToLoad[index] = m;
        }
    }
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        s += kgToLoad[i] * prOr[i];
    }
    std::cout <<std::fixed<<std::setprecision(2)<< s << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << std::fixed <<std::setprecision(3) << kgToLoad[i] << std::endl;
    }
}