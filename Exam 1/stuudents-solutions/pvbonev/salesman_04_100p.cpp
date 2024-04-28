#include <bits/stdc++.h>

const int MAX = 101;
unsigned short n;

double m,a,b,sum;//sum stores the result

struct Pair
{
public:
    double availableKilos;
    double pricePerKilo;
    double takenKilos;
    int originalIndex;
};

Pair pairs[MAX];


bool cmp(const Pair a,const Pair b)
{
    return a.pricePerKilo > b.pricePerKilo;
}

bool cmp2(const Pair a, const Pair b)
{
    return a.originalIndex < b.originalIndex;
}



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>m>>n;

    for(std::size_t i = 0; i < n; ++i)
    {
        std::cin>>a >>b;
        pairs[i].availableKilos = a;
        pairs[i].pricePerKilo = b;
        pairs[i].originalIndex = i;

    }

    std::sort(pairs,pairs + n,cmp);

    int i = 0;
    bool flag = true;
    while(flag)
    {
        if(m - pairs[i].availableKilos >= 0)
        {
            sum += pairs[i].availableKilos * pairs[i].pricePerKilo;//add to the sum
            pairs[i].takenKilos = pairs[i].availableKilos;// write down how much weve taken
            m -= pairs[i].availableKilos;//update the mass
            i++;// move to next spice

        } else 
        {
            sum += m * pairs[i].pricePerKilo;
            pairs[i].takenKilos = m;

            flag = false;
        }
    }

    std::sort(pairs,pairs + n, cmp2);


    std::cout<<std::fixed << std::setprecision(2)<<sum<<std::endl;
    for(std::size_t i = 0; i < n; ++i)
    {
        std::cout<<std::fixed << std::setprecision(3)<<pairs[i].takenKilos<<std::endl;
    }    
}