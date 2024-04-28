#include <bits/stdc++.h>
using namespace std;

int long long n, m, k;

struct elem
{
public:
    int long long ind;
    int long long cluster;
    int long long value;

    bool operator<(const elem &other) const
    {
        // if (this->cluster < other.cluster)
        // {
        //     return true;
        // }
        // if (this->cluster == other.cluster)
        // {
        //     return this->value < other.value;
        // }

        if (this->cluster < other.cluster && this->value < other.value)
        {
            return true;
        }
        
        if (this->cluster == other.cluster)
        {
            return this->value < other.value;
        }
        if(this->value == other.value)
        {
            return this->cluster < other.cluster;
        }
        return false;
    }
};

// struct elem
// {
//     long long ind;
//     long long value;
//     bool operator<(const elem& other)
//     {
//         return this->value < other.value;
//     }
// };

struct Interval
{
    int long long l;
    int long long r;
};

vector<elem> A;
vector<Interval> It;

void fl(long long l, long long r)
{
    for (long long i = l - 1; i < r; i++)
    {
        A[i].cluster++;
    }
}

int long long calc(long long l, long long r)
{
    long long sum =0;
    for(int i = l-1; i < r; i++)
    {
        sum += A[i].value;
    }

    return sum;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    priority_queue<elem> pq;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        int long long t;
        cin >> t;
        A.push_back({i, 0, t});
    }

    for (int i = 0; i < m; i++)
    {
        int long long l;
        int long long r;

        cin >> l >> r;
        It.push_back({l, r});
        fl(l, r);
    }

    for (long long i = 0; i < A.size(); i++)
    {
        if(A[i].value > 0)
        {
            pq.push(A[i]);
        }
    }

    // for (long long i = 0; i < A.size(); i++)
    // {
    //     cout << "e: " << A[i].ind << " " << A[i].cluster << " " << A[i].value << endl;
    // }

    // cout << "el: " << pq.top().ind << " " << pq.top().cluster << " " << pq.top().value << endl;

    while (!pq.empty() && k > 0)
    {

        elem tmp = pq.top();
        // cout << "v: " << tmp.value << endl;
        pq.pop();
        while (tmp.value > 0 && k > 0)
        {
            A[tmp.ind].value--;
            tmp.value--;
            k--;
        }
        if(tmp.value > 0)
        {
            pq.push(tmp);
        }
    }

    long long finalSum = 0;
    for (long long i = 0; i < It.size(); i++)
    {
        finalSum += calc(It[i].l, It[i].r);
    }

    // for (long long i = 0; i < A.size(); i++)
    // {
    //     cout << "t : "<< A[i].value << endl;
    // }

    

    cout << finalSum << endl;
}