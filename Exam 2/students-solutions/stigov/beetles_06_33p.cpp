#include <bits/stdc++.h>
using namespace std;

struct edge
{
    long long a, b, c;

    bool operator<(const edge &other)
    {
        return c < other.c;
    }
};

struct bug
{
    long long ind;
    long long x, y;

    bool operator<(const bug &other)
    {
        if (x * x + y * y < other.x * other.x + other.y * other.y)
            return true;

        if (x == other.x)
            return y < other.y;

        return x < other.x;
    }

    // bool operator<(const bug &other)
    // {
    //     // if (x == other.x)
    //     //     return y < other.y;

    //     return (x - other.x)*(x - other.x) < (y - other.y)*(y - other.y);
    // }
};

long long calc(long long x1, long long y1, long long x2, long long y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

vector<edge> e;
bug b[100005];
long long d[100005];
long long par[100005];
long long n;
long long ans = 0;

long long find(long long a)
{
    if (par[a] == 0)
        return a;

    return par[a] = find(par[a]);
}

void uni(long long a, long long b)
{
    a = find(a);
    b = find(b);

    if (d[a] > d[b])
    {
        par[b] = a;
    }
    else
    {
        par[a] = b;
        if (d[a] == d[b])
            d[b]++;
    }
    return;
}

int main()
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> b[i].x >> b[i].y;
        b[i].ind = i;
    }

    sort(b + 1, b + n + 1);

    for (long long i = 1; i < n; i++)
    {
        for (long long j = i+1; j <= n; j++)
        {
            if(j > i+2 && calc(b[i].x, b[i].y, b[j].x, b[j].y) > calc(b[i].x, b[i].y, b[j-1].x, b[j-1].y))
            {
                break;
            }
            e.push_back({b[i].ind, b[j].ind, calc(b[i].x, b[i].y, b[j].x, b[j].y)});
        }
    }

    // for (long long i = 1; i < n; i++)
    // {
    //     // if(j > i+1 && calc(b[i].x, b[i].y, b[j].x, b[j].y) > calc(b[i].x, b[i].y, b[j-1].x, b[j-1].y))
    //     // {
    //     //     break;
    //     // }
    //     e.push_back({b[i].ind, b[i + 1].ind, calc(b[i].x, b[i].y, b[i + 1].x, b[i + 1].y)});
    // }

    sort(e.begin(), e.end());

    for (auto v : e)
    {
        if (find(v.a) != find(v.b))
        {
            uni(v.a, v.b);
            ans += v.c;
        }
    }

    cout << ans;

    return 0;
}