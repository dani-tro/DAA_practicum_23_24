#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=701;
int a[MAXN], b[MAXN], c[MAXN];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        c[i]=i;
    }
    int maxres=0;
    do
    {
        for(int i=0; i<n; i++)
          b[i]=a[i];
        int tekres=0;
        for(int j=1; j<n-1; j++)
        {
            int left = c[j]-1; int right = c[j]+1;
            while(b[left]==0) left--;
            while(b[right]==0) right++;
            tekres = tekres + b[c[j]]*(b[left]+b[right]);
            b[c[j]] =0;
        }
        if (maxres<tekres) maxres = tekres;
    }while(next_permutation(c+1,c+n-1));
    cout << maxres << '\n';
    return 0;
}