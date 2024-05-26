#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ull = unsigned long long;

struct Point {
    long x;
    short y;
};

struct Edge {
    long a;
    long b;
    ull weight;
};

bool operator < (const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

ull dist(const Point& a, const Point& b) {
    ull dx = a.x - b.x;
    ull dy = a.y - b.y;

    return dx * dx + dy * dy;
}

Point points[100000];
vector<Edge> graph;
long parents[100000];
long sizes[100000];

long find(long t) { 
    if (parents[t] == t)
    {
        return t;
    }

    long p = find(parents[t]);
    parents[t] = p;
    return p;
}

void unions(long a, long b) {
    long pa = find(a);
    long pb = find(b);

    if (pa == pb) {
        return;
    }

    if (sizes[pa] < sizes[pb])
    {
        parents[pa] = pb;
        sizes[pb] += sizes[pa];
    }
    else {
        parents[pb] = pa;
        sizes[pa] += sizes[pb];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long n; cin >> n;

    for (long i = 0; i < n; i++)
    {
        long x; short y;
        cin >> x >> y;
        points[i]=Point{x, y};
        for (long j = 0; j < i; j++)
        {
            graph.push_back(Edge{ i,j, dist(points[i], points[j]) });
        }
    }
    
    for (long i = 0; i < n; i++)
    {
        parents[i] = i;
        sizes[i] = 1;
    }
    ull sum = 0;

    sort(graph.begin(), graph.end());
    for (auto& e : graph)
    {
        if (find(e.a) != find(e.b)) {
            unions(e.a, e.b);
            sum += e.weight;
        }
    }
    cout << sum << endl;
}