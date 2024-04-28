#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long n, k;
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

  long atomsLen = 1;

  for (size_t i = 0; i < n; i++)
  {
    //cout << atoms[i] << ' ';

    long currLen = 1;
    size_t j = i+1;
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
      break;
    }
  }
  
  cout << atomsLen;
}