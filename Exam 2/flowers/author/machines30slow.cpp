#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

const int MaxN=20000;

int places[MaxN+1];
vector<int> line;

int main(){
   int k, mc, mt;
   scanf("%d", &k);
   if (k>2)
      cout << "0" << endl;

   else {
      for (int i=1;i<=20000;i++)
         places[i] = 0;
      scanf ("%d", &mc);
      for (int i=1;i<=mc;i++){
        scanf("%d", &mt);
        places[mt] = i;
      }
      scanf("%d", &mc);
      for (int i=1; i<=mc; i++){
         scanf("%d", &mt);
         line.push_back(mt);
      }
      for (int i=0; i< line.size()-1; i++)
        for (int j=i+1; j<line.size(); j++)
            if ((places[line[i]] != 0) && (places[line[j]] != 0) && (places[line[i]]>places[line[j]])){
                cout << "0" << endl;
                return 0;
            }
      cout << "1"<<endl;;
   }
   return 0;
}


