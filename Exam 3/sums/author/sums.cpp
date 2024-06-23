#include<iostream>
using namespace std;

int n,a,b;
const int max_n=1000;
const int max_b=1000;
int d[max_n];
int h[max_b];


int main()
{
  cin >> n >> a >> b;
  for(int i=0;i<n;i++) cin >> d[i];
  
  h[0]=1;
  for(int i=0;i<n;i++) 
  {
    for(int j=b;j>0;j--)
    if(j-d[i]>=0)
    if(h[j-d[i]]==1) 
     h[j]=1;   
  }
  int c=0;
  for(int i=a;i<=b;i++) c+=h[i];
  cout << c << endl;  
}
