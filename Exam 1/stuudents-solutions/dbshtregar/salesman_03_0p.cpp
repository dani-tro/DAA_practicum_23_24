#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
int m, n;
double S, s = 0, diff;

struct product
{
    double a, b;
    bool operator<(const product &other) const
    {
        return this->b < other.b;
    }

};
double c[MAXN];
product p[MAXN], newP[MAXN];




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>m;
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cin>>p[i].a>>p[i].b;
        newP[i].a = p[i].a;
        newP[i].b = p[i].b;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n - i - 1; j++)
        {
            if(p[i] < p[j+1])
            {
                swap(p[j], p[j+1]);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        s += p[i].a;
        S += p[i].a * p[i].b;
        c[i] = newP[i].a;
    }

    if(s > m)
    {
        diff = s - (double)m;
        S -= diff * p[n-1].b;

    }

    for(int i = 0 ; i < n; i++)
    {
        if(p[n-1].b == newP[i].b)
        {
            c[i] = newP[i].a - diff;
        }
        else
        {
            c[i] = newP[i].a;
        }
    }
    cout << fixed << setprecision(2) << S << endl;
    for(int i = 0 ; i < n; i++)
    {
        cout << fixed << setprecision(3) << c[i] << endl;
    }




    return 0;
}

