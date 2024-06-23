#include <stdio.h>
#include <list>
#include <string.h>
#define MAX_VALUE 1000000
#define MAX 20000

using namespace std;

struct Arc {
    int x;
    int d;
};

list<Arc> B[MAX];

int dist[MAX];
int visit[MAX];

int posHeap[MAX];
int heap[MAX];
int hsize;

int n,m,k;
int minP;

void read() {
    int i,j, x,y,p, t;
    scanf("%d %d %d", &n, &m, &k);
    for(i=0; i<m; i++) {
        scanf("%d %d %d %d", &x, &y, &p, &t);
        Arc arc1, arc2;
        arc1.x = y-1; arc1.d = t-p;
        arc2.x = x-1; arc2.d = t-p;
        B[x-1].push_back(arc1);
        B[y-1].push_back(arc2);
    }
}

void hswap(int i, int j) {
    posHeap[heap[i]] = j;
    posHeap[heap[j]] = i;
    int k = heap[i];
    heap[i] = heap[j];
    heap[j] = k;
}

void moveDown(int x) {
    while (x< (hsize>>1)) {
        int child = 2*x +1;
        if (child + 1 < hsize && dist[heap[child + 1]] < dist[heap[child]]) {
            child++;
        }
        if (dist[heap[x]] <= dist[heap[child]]) {
            break;
        }
        hswap(x, child);
        x = child;
    }
}

void moveUp(int x) {
    while (x>0) {
        int parent = (x-1)>>1;
        if (dist[heap[x]] >= dist[heap[parent]]) break;
        hswap(x, parent);
        x = parent;
    }
}

int removeMin() {
    int res = heap[0];
    int last = heap[--hsize];
    if (hsize > 0) {
        heap[0] = last;
        moveDown(0);
    }
    return res;
}

int add(int x) {
    posHeap[x] = hsize;
    heap[hsize++] = x;
    moveUp(hsize-1);
}

void dijkstra() {

    dist[0] = 0;
    hsize = 0;
    add(0);

    int i;
    int min, k;
    while (visit[n-1] == 1) {
        k = removeMin();
        visit[k] = 0;
        for(list<Arc>::iterator it=B[k].begin(); it !=B[k].end(); it++) {
            if(visit[it->x] && dist[it->x]>dist[k]+it->d) {
                dist[it->x] = dist[k] + it->d;
                if (posHeap[it->x]>=0) moveUp(posHeap[it->x]);
                else add(it->x);
            }
        }
    }
}


int main() {
    read();
    int i,j;
    for(i=0; i<n; i++) {
        visit[i] = 1;
        dist[i] = MAX_VALUE;
        posHeap[i] = -1;
    }
    dijkstra();
    printf("%d\n", k - dist[n-1]);

	return 0;
}
