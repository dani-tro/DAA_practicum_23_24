#include<bits/stdc++.h>
using namespace std;

unsigned n,k;//apt & TVs
vector<unsigned> d;
vector<bool> ima;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n>>k;
    unsigned help;
    unsigned long long obR=0;

    for(int i=0;i<n-1;++i){
        cin>>help;
        d.push_back(help);
        obR+=help;
    }
    unsigned res=0;
    unsigned maxR=0;
    unsigned sredno=obR/k;
    help=0;


    for(int i=0;i<n-1;++i){
         help += d[i];
        if (help >= sredno) {
            ima.push_back(1);
            if(help!=sredno)
                maxR = max(maxR,help-d[i]);
            help = d[i];
        }
        else {
            ima.push_back(0);
                maxR = max(maxR,help-d[i]);
        }
    }

    for(int i=0;i<n-1;++i){
        cout<<ima[i]<<' ';
    }


    cout<<maxR;
    return 0;
}