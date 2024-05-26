#include <bits/stdc++.h>
#define MAXN 20010
using namespace std;

int k, n, a, b;
bool gr[MAXN][MAXN];
int incom[MAXN];
int totalUsed;
bool used[MAXN];
queue<int> q;
vector<int> sorting;

int topSort(){
    int cnt = 0;
    for(int i = 0; i < MAXN; i++) {
        if(incom[i] == 0 && used[i]) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int curr = q.front();
        // cout << curr << "  ";
        q.pop();
        cnt++;
        sorting.push_back(curr);
        for(int i = 0; i < MAXN; i++) {
            if(gr[curr][i]) {
                // cout << i << " inc " << incom[i] << "    ";
                incom[i]--;
                if(incom[i] == 0) q.push(i);
            }
        }
        // cout << endl;
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> n;
        a = -1;
        for(int j = 0; j < n; j++) {
            if(a != -1) a = b;
            cin >> b;
            if(used[b] == false) totalUsed++;
            used[b] = true;
            if(a == -1) {
                a = b;
                continue;
            }
            
            if(!gr[a][b]) incom[b]++;
            gr[a][b] = true;
        }
    }

    int ts = topSort();
    if(ts == totalUsed) cout << 1;
    else cout << 0;

    return 0;
}