#include<iostream>
#include<algorithm>
#include<assert.h>
#include<iomanip>
#define MAXN 100
#define eps 1e-6
using namespace std;
struct object {
    double cap;
    double price;
    int ind;
};
object obj[MAXN];
double ans[MAXN];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double m;
    int n;
    cin >> m >> n;
        assert((1-eps<=m)&&(m<=1000+eps));
        assert((1<=n)&&(n<=100));
        for (int i=0; i<n; i++) {
            assert(cin >> obj[i].cap >> obj[i].price );
            assert((1-eps<=obj[i].cap)&&(obj[i].cap<=100+eps));
            assert((1-eps<=obj[i].price)&&(obj[i].price<=1000+eps));
            obj[i].ind=i;
            ans[i]=0;
        }
        sort(obj,obj+n,[] (object& l, object& r) {
             if (l.price>r.price+eps) return true;
             if ((abs(l.price-r.price)<eps)&&(l.ind<r.ind)) return true;
             return false;
        });
        double val=0;
        for (int i=0; i<n; i++) {
            //if (i>0) assert(abs(obj[i].price-obj[i-1].price)>eps);
            auto [cap, price, ind]=obj[i];
            cap=min(cap,m);
            m-=cap;
            val+=cap*price;
            ans[ind]=cap;
            if (m<eps) break;
        }
        cout << endl ;
        cout << fixed << setprecision(2) << val << "\n";
        for (int i=0; i<n; i++) {
            cout << fixed << setprecision(3) << ans[i] << "\n";
        }

    return 0;
}
