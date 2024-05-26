#include <bits/stdc++.h>
using namespace std;

uint32_t n;

struct coords
{
    uint32_t x;
    uint32_t y;

    bool operator<(const coords& other) const
    {
        return x < other.x || (x == other.x && y < other.y);
    }
};

struct unionfind
{
    vector<uint32_t> parent, size;
    uint32_t max_size;

    unionfind() {}
    unionfind(uint32_t n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        max_size = 1;
        for (size_t i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int get_parent(int x)
    {
        if (parent[x] == x)
            return x;
        else
            return get_parent(parent[x]);
    }

    void merge(int x, int y)
    {
        x = get_parent(x);
        y = get_parent(y);

        if (x == y)
            return;

        if (size[x] < size[y])
        {
            size[y] += size[x];
            parent[x] = y;
            if(max_size < size[y])
                max_size = size[y];
        }
        else
        {
            size[x] += size[y];
            parent[y] = x;
            if(max_size < size[x])
                max_size = size[x];
        }
    }

    int get_size(int x)
    {
        return size[get_parent(x)];
    }
};

struct edges
{
    uint32_t from;
    uint32_t to;
    uint64_t dist;

    bool operator< (const edges& other) const
    {
        return dist < other.dist;
    }
};


uint64_t get_dist(const coords& p, const coords& q)
{
    uint64_t p1,p2;
    if(p.x > q.x)
        p1 = (p.x - q.x);
    else
        p1 = (q.x - p.x);

    if(p.y > q.y)
        p2 = (p.y - q.y);
    else
        p2 = (q.y - p.y);

    return p1*p1 + p2*p2;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    vector<coords> b;

    for (size_t i = 0; i < n; i++)
    {
        coords p;
        cin >> p.x >> p.y;

        b.push_back(p);
    }
    
    sort(b.begin(), b.end());

    vector<edges> e;

    for (uint32_t i = 0; i < b.size() - 1; i++)
    {
        for (uint32_t j = 1; j <= 5; j++)
        {
            if(i+j >= b.size())
                break;

            e.push_back((edges){i+1, i+1+j, get_dist(b[i], b[i+j])});
        }
        
        // e.push_back((edges){i+1, i+2, get_dist(b[i], b[i+1])});
    }
    
    sort(e.begin(), e.end());

    unionfind dsu(n);

    uint64_t min_cost = 0;

    for(edges cur : e)
    {
        if(dsu.max_size == n)
            break;
            
        if(dsu.get_parent(cur.from) != dsu.get_parent(cur.to))
        {
            min_cost += cur.dist;
            dsu.merge(cur.from, cur.to);
        }
    }
    cout << min_cost << endl;
    return 0;
}
