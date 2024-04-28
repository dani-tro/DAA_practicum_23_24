#include <iostream>
#include<algorithm>
#include <iomanip>
using namespace std;

long getIndex(double pr, double kg, double* prOr, double* kgOrig, int n, int index) {
    for (long i = index; i < n; i++)
    {
        if (kg == kgOrig[i] && pr == prOr[i]) {
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
    double kg, cena;
    std::pair<double, double>* cenaKg = new std::pair<double, double>[n];
    double* kgOrig = new double[n];
    double* kgToLoad = new double[n];
    double* prOr = new double[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> kg;
        kgOrig[i] = kg;
        std::cin >> cena;
        prOr[i] = cena;
        std::pair<double, double> a = std::make_pair(cena, kg);
        cenaKg[i] = a;
        kgToLoad[i] = 0;
    }
    std::sort(cenaKg, cenaKg + n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (m >= cenaKg[i].second) {
            m = m - cenaKg[i].second;
            int index = getIndex(cenaKg[i].first, cenaKg[i].second, prOr, kgOrig, n, 0);
            while (kgToLoad[index] != 0) {
                index = getIndex(cenaKg[i].first, cenaKg[i].second, prOr, kgOrig, n, index + 1);
            }
            kgToLoad[index] = cenaKg[i].second;
        }
        else {
            int index = getIndex(cenaKg[i].first, cenaKg[i].second, prOr, kgOrig, n, 0);
            while (kgToLoad[index] != 0) {
                index = getIndex(cenaKg[i].first, cenaKg[i].second, prOr, kgOrig, n, index+1);
            }
            kgToLoad[index] = m;
            m = 0;
        }
    }
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        s += kgToLoad[i] * prOr[i];
    }
    std::cout << std::fixed << std::setprecision(2) << s << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << std::fixed << std::setprecision(3) << kgToLoad[i] << std::endl;
    }
}