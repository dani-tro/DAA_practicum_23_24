#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1005

int dp[MAX][MAX];
int n;

struct point {
  int x, y;
};


vector<point> points;

int price(point a, point b) {
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int cheapest() {
  int sum = 0, prev = 0;
  int minP = 0;

  for(int i = 0; i < n; ++i) {
    int j = 0;
    for (j = 0; j < n; j++)
    {
      sum += price(points[i], points[j]);
      dp[i][j] = sum;
    }

    if(i == 0) minP = sum;

    if(dp[i][j]) minP = dp[i][j];
    else { 
      minP = min(sum, minP);
      dp[i][j] = minP;
    }

    prev = sum;
  }

  return minP;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  for (size_t i = 0; i < n; i++)
  {
    point curr;
    cin >> curr.x >> curr.y;
    points.push_back(curr);
  }

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      dp[i][j] = 0;
    }
    
  }
  
  cout << cheapest();

}