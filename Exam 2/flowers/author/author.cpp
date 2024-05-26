#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int MaxN=20000;

vector<int> cgraph[MaxN+1];
int stat[MaxN+1];

bool foundcycle;

void inputrows()
{
  int rc;                 // брой на линиите в цеха
  int re;                 // брой на машините в поредната линия
  int el;                 // в el се чете видът на поредната машина в линията
  int pel;                // в pel се пази вида на предната машина в линията

  scanf("%d",&rc);
  for (int i=1;i<=rc;i++)
  {
    scanf("%d",&re);
    scanf("%d",&pel);
    for (int j=2;j<=re;j++)
    {
      scanf("%d",&el);
      cgraph[pel].push_back(el);
      pel=el;
    }
  }
}

void DFS(int v)
{
  stat[v]=1;
  for (int i=0;i<cgraph[v].size();i++)
  {
    if (stat[cgraph[v][i]] == 0)
      {
        DFS(cgraph[v][i]);
        if (foundcycle) break;
      }
    else
      if (stat[cgraph[v][i]] == 1)
      {
        foundcycle = true;
        break;
      }
  }
  stat[v]=2;
}

int main()
{
    for (int m=1;m<=MaxN;m++)
    {
      cgraph[m].clear();
      stat[m]=0;
    }
    foundcycle = false;
    inputrows();

    for (int m=1;m<=MaxN;m++)
    {
      if (stat[m] == 0)
        DFS(m);
      if (foundcycle)
        break;
    }
    if (foundcycle)
      cout << "0";
    else
      cout << "1";

    cout << endl;

    return 0;
}
