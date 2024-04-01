# include <bits/stdc++.h>
using namespace std;
struct Point {
    double x, y;
};
const int maxm = 1e5+5;

double area(Point A, Point B, Point C) {
    return abs((B.x - A.x)*(C.y - A.y) - (C.x - A.x)*(B.y - A.y));
}

Point mid (Point A, Point B) {
    Point P;
    P.x = (A.x + B.x)/2.0;
    P.y = (A.y + B.y)/2.0;
    return P;
}

double dist (Point A, Point B) {
    return ((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
}

Point solve (Point P, Point A, Point B, double target) {
    Point B1 = B;
    for (int i = 1; i <= 1000000; i++) {
        Point M = mid (A, B);
        double areaBMP = area(B1, M, P);
        //cout << std::fixed << std::setprecision(6) << P.x << " " << P.y << " " << A.x << " " << A.y << " " << B.x << " " << B.y << " " << target << " :: " << areaBMP << endl;
        if (areaBMP > target) {
            A = M;
        } else {
            B = M;
        }
    }
    return mid(A,B);
}
int main() {
    Point A, B, C, P;
    A.x = 0;
    A.y = 0;
    C.x = 0;
    cin >> C.y;
    cin >> B.x;
    cin >> B.y;
    cin >> P.x;
    cin >> P.y;

    if (area (A, B, P) == 0) {
        swap (A, C);
    }

    if (area (A, C, P) == 0) {
        swap (A, B);
    }

    double areaABC = area(A, B, C);
    double areaABP = area(A, B, P);
    double areaACP = area(A, C, P);

    Point ans;
    if (areaABP < areaACP) {
        ans = solve (P, A, C, areaABC/2.0);
    } else {
        ans = solve (P, A, B, areaABC/2.0);
    }

    cout << std::fixed << std::setprecision(6) <<  ans.x << " " << ans.y << endl;

}
