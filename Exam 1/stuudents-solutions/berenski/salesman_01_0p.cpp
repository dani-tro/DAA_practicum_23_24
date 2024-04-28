#include<bits/stdc++.h>

using namespace std;
const int MAXN=105;


int n;
double m;
double sum;
priority_queue<tuple<double,double,int>> price_prod;//price
vector<double> prod_take(MAXN);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        double a,b;
        cin>>a>>b;
        price_prod.push(make_tuple(b,a,i));
    }
    while(!price_prod.empty()&&m>0){
        tuple<double,double,int> cur=price_prod.top();
        price_prod.pop();
        if(m>=get<1>(cur)){
            m-=get<1>(cur);
            prod_take[get<2>(cur)]=get<1>(cur);
        }
        else {
            prod_take[get<2>(cur)]=m;
        }
        sum+=(prod_take[get<2>(cur)]*get<0>(cur));
    }
   cout << fixed << setprecision(2) << sum << endl;
    for(int i=0;i<n;i++){
    cout << fixed << setprecision(3) << prod_take[i] << endl;
    }
}