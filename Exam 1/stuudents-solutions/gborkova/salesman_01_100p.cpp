#include <bits/stdc++.h>
#define MAX (unsigned long long)1e5

using namespace std;

double m;
int n;

double s;
double P[MAX];
//double KG[MAX];

int main() {
    vector<pair<pair<double, double>, int>> A; // kg, p

    scanf("%lf %i", &m, &n);
    for (int i = 0; i < n; ++i) {
        double temp1, temp2;
        scanf("%lf %lf", &temp1, &temp2);
        A.emplace_back(make_pair(temp2, temp1), i);

        //scanf("%lf %lf", &KG[i], &P[i]);
    }

    sort(A.begin(), A.end(), greater());

    for (int i = 0; i < n; ++i) {
        if (m <= 0)
            break;
        if (m >= A[i].first.second) {
            m -= A[i].first.second;
            s += A[i].first.second*A[i].first.first;
            P[A[i].second] = A[i].first.second;
        }
        else {
            s += m*A[i].first.first;
            P[A[i].second] = m;
            m = 0;
        }
    }

    printf("%.2lf\n", s);
    for (int i = 0; i < n; ++i) {
        printf("%.3lf\n", P[i]);
    }

    return 0;
}
