#include<iostream>
using namespace std;

int n,a,b;
const int max_n=1000;
const int max_b=1000;
int d[max_n];
int h[max_b];

int s=0;
void go(int k)
{
  if(k>=n) return;
  s += d[k];
  if(a<=s && s <=b) h[s]=1;
  if(s<b) go(k+1);
  s -= d[k];
  go(k+1);    
}

int main()
{
  cin >> n >> a >> b;
  for(int i=0;i<n;i++) cin >> d[i];
  go(0); 
  int c=0;
  for(int i=a;i<=b;i++) c+=h[i];
  cout << c << endl; 
    
}
