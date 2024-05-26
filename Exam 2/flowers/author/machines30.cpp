#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int MaxN=20000;

vector<int> Line1;
vector<int> Line2;

vector<int> ModLine1;
vector<int> ModLine2;

bool inLine1[MaxN+1];
bool inLine2[MaxN+1];

int main(){
   int k, mc, mt;
   scanf("%d", &k);
   if (k>2)
      cout << "0" << endl;

   else {
      for (int i=1;i<=20000;i++){
         inLine1[i] = false;
         inLine2[i] = false;
      }
      scanf ("%d", &mc);
      for (int i=1;i<=mc;i++){
        scanf("%d", &mt);
        Line1.push_back(mt);
        inLine1[mt] = true;
      }
      scanf("%d", &mc);
      for (int i=1; i<=mc; i++){
         scanf("%d", &mt);
         Line2.push_back(mt);
         inLine2[mt] = true;
      }
      for (int i=0;i<Line1.size();i++)
        if (inLine2[Line1[i]])
           ModLine1.push_back(Line1[i]);
      for (int i=0;i<Line2.size();i++)
        if (inLine1[Line2[i]])
           ModLine2.push_back(Line2[i]);

      if (ModLine1.size() != ModLine2.size())
            cout << "0" << endl;
      else{
         for (int i=0;i<ModLine1.size();i++)
            if (ModLine1[i] != ModLine2[i]){
                cout << "0" << endl;
                return 0;
            }
         cout << "1" << endl;
      }
   }
   return 0;
}


