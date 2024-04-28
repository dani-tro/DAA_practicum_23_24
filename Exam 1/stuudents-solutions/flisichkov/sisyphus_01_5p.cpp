#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define MAX 1'000'005

struct path {
  long l, r, val;
};

struct event {
  int val, type; //left limit = 1, right limit = -1, otherwise = 0
};

long n, m, k;
long a[MAX];
pair<event, event> b[MAX];

event path[MAX];
pair<int, int> routes[MAX];

int main() {
    ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> k;
  for (size_t i = 0; i < n; i++)
  {
    cin >> path[i].val;
    path[i].type = 0;
  }

  for (size_t i = 0; i < m; i++)
  {
    int l, r;
    cin >> l >> r;
    
    if(l == r) 
      path[l].type = 0;
    
    path[l-1].type = 1;
    path[r-1].type = -1;
    

    routes[i].first = l;
    routes[i].second = r;
  }
  
  //find max intersection   dunno do later    some sweep line thingy
  /*
  int overlapIdx = 0;
  for (size_t i = 0; i < n; i++)
  {
    if(path[overlapIdx].type < path[i].type)
      overlapIdx = i;
  }
  
  int p = overlapIdx;
  while(path[p].type >= 0 && path[p].val > 0 && k > 0) {
    if (path[p].val - k >= 0)
    {
      path[p].val -= k;
      k = 0;
    }
    else {
      int rest = k - path[p].val;
      path[p].val -= rest;
      k -= rest;
    }
    
    cout << "p: " << p << endl;

    ++p;
  }
  */

  //sort(routes[0], routes[m-1]);

  int c = 0, maxC = 0, maxIdx = 0;
  for (size_t i = 0; i < n; i++)
  {
    if(path[i].type == 1) {
      ++c;
    }
    else if(path[i].type == -1) {
      --c;
    }

    if(c > maxC)
      ++maxIdx;

    maxC = max(c, maxC);
  }
  
  int p = maxIdx;
  while (path[p].type != -1 && k > 0 && path[p].val > 0)
  {
    if(path[p].val - k >= 0) {
      path[p].val -= k;
      k = 0;
    }
    else {
      int rest = k - path[p].val;
      path[p].val -= rest;
      k -= rest;
    }
  }
  




  //calculate sum
  int totalSum = 0;
  for (size_t i = 0; i < m; i++)
  {
    int l = routes[i].first;
    int r = routes[i].second;

    for (size_t j = l-1; j < r; j++)
    {
        totalSum += path[j].val;
        //cout << '(' << path[j].val << ", " << path[j].type << ") ";
    }
  }
  
  cout << totalSum;
}