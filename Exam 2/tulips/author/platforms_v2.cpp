/**
2018 Sofia autumn tournament in informatics
Task  : platforms
Group : D
Author: Desislava Ratcheva
*/
#include <iostream>
using namespace std;

short A[2][1001],i,h,current_row,prev_row=1;
int   n,m,platforms;

int main () {
  for (cin>>n>>m; n--; prev_row^=1, current_row^=1) for (i=1; i<=m; i++) {
    cin >> A[current_row][i];
    if (A[current_row][i]!=A[prev_row][i] and A[current_row][i]!=A[current_row][i-1]) platforms++;
  }
  cout << platforms << endl;
  return 0;
}

