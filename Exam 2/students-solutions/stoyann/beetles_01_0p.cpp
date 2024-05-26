#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX 100100
struct edge
{
    int a,b,c;
} edges[MAX];
bool sortEdges(const edge& u, const edge& v)
{
    return u.c <= v.c;
}
int n,m,x,y,z,par[MAX],d[MAX],maxM,idx;
pair<int,int> beetles[MAX];
bool sortBeetles(pair<int,int> b1, pair<int,int> b2)
{
    return b1.first+b1.second <= b2.first+b2.second;
}

int find(int a)
{
    if(par[a]==-1) return a;
    return par[a]=find(par[a]);
}

void uni(int a,int b)
{
    a=find(a);
    b=find(b);

    if(d[a]>d[b])
    {
        par[b]=a;
    }
    else if (d[b]>d[a])
    {
        par[a]=b;
    }
    else
    {
        par[a]=b;
        d[b]++;
    }
    
}

int mst()
{
    fill(par, par+n, -1);
    int sum=0;
    for(int i=0;i<idx;++i)
    {
        if(find(edges[i].a) != find(edges[i].b))
        {
            uni(edges[i].a,edges[i].b);
            sum+=edges[i].c;
            //cout << "Curr: " << sum << endl;
        }
    }
    return sum;
}

int id(int x,int y)
{
    return x*maxM+y;
}

int findPrice(int a,int b,int c,int d)
{
    return (a-c)*(a-c) + (b-d)*(b-d);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin >> x >> y;
        beetles[i] = {x,y};
        if(maxM<x)
            maxM=x;
        if(maxM<y)
            maxM=y;
    }
    //sort(beetles,beetles+n,sortBeetles);

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i != j)
            {
                edges[idx]={i, j, findPrice(beetles[i].first,beetles[i].second,beetles[j].first,beetles[j].second)};
                ++idx;
            }
        }
    }
    sort(edges,edges+idx,sortEdges);

    /*for(int i=0;i<idx;++i)
    {
        cout << edges[i].a << ' ' << edges[i].b << ' ' << edges[i].c << endl;
    }*/

    cout << mst() << endl;

    return 0;
}