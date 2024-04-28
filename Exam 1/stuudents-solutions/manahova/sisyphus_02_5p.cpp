#include <bits/stdc++.h>
using namespace std;

#define MAXN 101000
#define MAXM 1001000

long long n, m, k, a[MAXN], l, r, inters, last_point, sum;

struct endpoint
{
    long long x;
    bool closing;

    bool operator<(const endpoint& other)
    {
        return x < other.x || (x == other.x && closing <= other.closing);
    }
};

endpoint endpoints[MAXM];

struct intersection
{
    long long x;
    long long cnt_int;
};

bool cmp_intr(const intersection& i1, const intersection& i2)
{
    return i1.cnt_int > i2.cnt_int;
}

intersection v[MAXN];
long long idx = 0;

int main()
{
    cin >> n >> m >> k;

    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    for (long long i = 1; i <= m; i++)
    {
        cin >> l >> r;
        endpoints[i] = {l, 0};
        endpoints[m + i] = {r, 1};
    }
    
    sort(endpoints, endpoints + 2 * m + 1);

    for (long long i = 1; i <= 2 * m; i++)
    {
        for (long long j = last_point + 1; j < endpoints[i].x; j++)
        {
            v[idx] = {j, inters};
            idx++;
            sum += a[j] * inters;
        }
        
        if (endpoints[i].closing == 0)
        {
            inters++;
            while (i < 2*m && endpoints[i + 1].x == endpoints[i].x && endpoints[i + 1].closing == 0)
            {
                i++;
                inters++;
            }

            v[idx] = {endpoints[i].x, inters};
            idx++;
            sum += a[endpoints[i].x] * inters;
        }
        else
        {
            v[idx] = {endpoints[i].x, inters};
            idx++;
            sum += a[endpoints[i].x] * inters;

            inters--;
            while (i < 2*m && endpoints[i + 1].x == endpoints[i].x && endpoints[i + 1].closing == 1)
            {
                i++;
                inters--;
            }
        }

        last_point = endpoints[i].x;
    }

    sort(v, v + idx, cmp_intr);
    intersection curr;
    idx--;
    while (k > 0)
    {
        curr = v[idx];
        idx--;
        if (idx < 0) break;
        while (a[curr.x] > 0 && k > 0)
        {
            a[curr.x]--;
            sum -= curr.cnt_int;
        }
    }

    cout << sum << endl;

    return 0;
}