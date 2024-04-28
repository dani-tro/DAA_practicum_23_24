#include <bits/stdc++.h>
using namespace std;
const unsigned MAX = 124;

unsigned n;
double m;
double a,b;
double brought_kg [MAX];

struct Spice{
    double av_kilo;
    double price;
    unsigned ptr;

    Spice (const double kg=0, const double pr=0, const unsigned it=0){
        av_kilo=kg;
        price=pr;
        ptr=it;
    }

    void print()const {
        cout<<av_kilo<<" "<<price<<" "<<ptr<<endl;
    }

    bool operator<(const Spice& other){
        if(price==other.price){
            return av_kilo<other.av_kilo;
        }

        return price<other.price;
    }
};

Spice storage[MAX];

int storage_iter;
double can_be_brought;
double sum=0;

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    cin>>m>>n;

    for(unsigned i=0;i<n;i++){
        cin>>a>>b;
        storage[i]=Spice(a,b,i);
    }

    for(unsigned i=0;i<n;i++){
        brought_kg[i]=0;
    }

    sort(begin(storage),&storage[n]);

    storage_iter=n-1;

    while(storage_iter>=0&&m>0){
        can_be_brought=min(storage[storage_iter].av_kilo,m);

        m-=can_be_brought;
        sum+=can_be_brought*storage[storage_iter].price;
        storage[storage_iter].av_kilo-=can_be_brought;

        brought_kg[storage[storage_iter].ptr]=can_be_brought;

        if(storage[storage_iter].av_kilo==0){
            storage_iter--;
        }
    }

    cout<<fixed<<setprecision(2)<<sum<<endl;
    for(int i=0;i<n;i++){
        cout<<fixed<<setprecision(3)<<brought_kg[i]<<endl;
    }

}
