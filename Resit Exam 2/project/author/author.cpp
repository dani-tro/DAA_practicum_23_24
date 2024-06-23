#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX 100000
#define MAXM 200000

using namespace std;
struct Task {
    int a,b;
    int t;
};

int m, n;
Task task[MAXM];
vector<Task> G[MAX], G2[MAX];
int num[MAX];

int main() {
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++) num[i] = 0;

    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &task[i].a, &task[i].b, &task[i].t);
        num[task[i].b]++;
        G[task[i].a].push_back(task[i]);

        G2[task[i].b].push_back(task[i]);
    }

    int topSort[MAX];
    int fTime[MAX], lTime[MAX];
    int k = 0;
    for(int i=0; i<n; i++)
        if (num[i] == 0) topSort[k++] = i;
    for(int i=0; i<n; i++) fTime[i] = 0;

    for(int i=0; i<k; i++) {
        int x = topSort[i];
        for(vector<Task>::iterator iter=G[x].begin(); iter != G[x].end(); iter++) {
            int y = iter->b;
            if (num[y] >0) {
                int time = fTime[x] + iter->t;
                if (fTime[y] < time) fTime[y] = time;
                num[y]--;
                if (num[y] == 0) topSort[k++] = y;
            }
        }
    }
    int max = fTime[0];
    for(int i=1; i<n; i++)
        if (max<fTime[i]) max = fTime[i];

    for(int i=0; i<n; i++) lTime[i] = max;

    for(int i=k-1; i>=0; i--) {
        int x = topSort[i];
        for(vector<Task>::iterator iter=G2[x].begin(); iter != G2[x].end(); iter++) {
            int y = iter->a;
            int time = lTime[x] - iter->t;
            if (lTime[y] > time) lTime[y] = time;
        }
    }

    printf("%d\n", max);

    for(int i=0; i<m; i++) {
        printf("%d %d\n", fTime[task[i].a],lTime[task[i].b] - task[i].t);
    }

    return 0;
}
