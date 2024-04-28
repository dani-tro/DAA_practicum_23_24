#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define MAX 1'000'005

int n, k;
vector<long> atoms;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  for (size_t i = 0; i < n; i++)
  {
    long curr;
    cin >> curr;
    atoms.push_back(curr);
  }
  
  sort(atoms.begin(), atoms.end());

  int atomsLen = 1;

  for (size_t i = 0; i < n; i++)
  {
    //cout << atoms[i] << ' ';

    int currLen = 1, j = i+1;
    while (atoms[j] - atoms[i] <= k)  
    {
      //cout << atoms[j] << ' ';
      ++currLen;
      ++j;
    }

    //cout << endl;

    atomsLen = max(atomsLen, currLen);
    currLen = 0;
    
    if(j >= n-1) {
      //cout << "break";
      break;
    }
  }
  
  cout << atomsLen;
}