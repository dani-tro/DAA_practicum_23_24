#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct item
{ int nom;
  double a,b,c;
};

void solve(double m, vector<item> items)
{
  // sort the items by b-values
    sort( items.begin(),items.end(),
          [](item x, item y) { return x.b > y.b; }
        );

    // solve the knapsack problem using greedy approach
    int n = items.size();
    double s = 0;
    for(int i=0; i<n; i++)
    { items[i].c = min(m,items[i].a);
      m = m - items[i].c;
      s = s + items[i].c*items[i].b;
    }

  // sort the items by nom
    sort( items.begin(),items.end(),
          [](item x, item y) { return x.nom < y.nom; }
        );

    cout << fixed << setprecision(2) << s << endl;
    for(int i=0; i<n; i++)
      cout << fixed << setprecision(3) << items[i].c << '\n';
    cout << endl;
}

int main()
{ double m;
  cin >> m;


  int n;
    cin >> n;
    vector<item> items(n);
    for(int i=0; i<n; i++)
    { items[i].nom = i;
      cin >> items[i].a >> items[i].b;
    }

    solve(m,items);

    cin >> m;


  return 0;
}
