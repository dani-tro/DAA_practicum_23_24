#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define MAXK 100100
#define MAXN 20100

void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int k, x, a;
int prevv;

//vector<int> gr[MAXN];
int gr[MAXN][MAXN];

int mx;

int in[MAXN];
queue<int> q;

vector<int> ans;

bool added[MAXN];
int counter;

int main()
{
    fast_IO();

    fill(in, in + MAXN, -1);

    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> x;


        for(int j = 0; j < x; j++) {
            cin >> a;

            if(!added[a]) {
                added[a] = true;
                counter++;
            }

            mx = max(mx, a);

            if(j == 0 && in[a] == -1) in[a] = 0;

            if(j != 0 && !gr[prevv][a]) {
                //gr[prevv].push_back(a);
                gr[prevv][a] = 1;

                if(in[a] == -1) in[a] = 1;
                else in[a]++;
            }

            prevv = a;
        }
    }

    for(int i = 1; i <= mx; i++) {
        if(in[i] == 0) q.push(i);
    }

    // for(int i = 1; i <= mx; i++) {
    //     cout << i << ": ";
    //     for(int j = 1; j <= mx; j++) {
    //         if(gr[i][j]) cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // for(int i = 1; i <= mx; i++) {
    //     if(in[i] != -1) {
    //         cout << i << ": " << in[i] << endl;
    //     }
    // }

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        ans.push_back(curr);

        // cout << curr << ": ";
        for(int u = 1; u <= mx; u++) {
            if(gr[curr][u]) in[u]--;
            // if(gr[curr][u]) cout << u << " ";
            if(gr[curr][u] && in[u] == 0) {
                q.push(u);
            }
        }
        // cout << endl;
    }

    // for(int i : ans) {
    //     cout << i << " ";
    // }
    // cout << endl;

    // cout << counter << endl;

    if(ans.size() == counter) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    // for(int i = 1; i <= mx; i++) {
    //     cout << i << ": ";
    //     for(int j = 1; j <= mx; j++) {
    //         if(gr[i][j]) cout << j << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}