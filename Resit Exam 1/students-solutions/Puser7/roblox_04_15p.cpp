#include <bits/stdc++.h>
#define MAXN 100000005
using namespace std;

int n, k;
int nums[MAXN];
queue<int> q;

int main() {

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long ways = 0;

    if(true) {
        long long sum = 0;
        long long total = 0;
        for(int i = n - 1; i > 0; i--) {
            sum = nums[i];
            total = 0;
            for(int j = i - 1; j >= 0; j--) {
                total += nums[j] * sum;
                sum += nums[j];
                if(total >= k) {
                    // cout << i << "   " << j << "  " << total << endl;
                    ways += j + 1;
                    break;
                }
            }
        }
    } else {
        int i = 0;
        int start = -1;
        int end = -1;
        int numCnt = 0;
        while(numCnt < 2) {
            q.push(nums[i]);
            if(nums[i] != 0) {
                if(start == -1) start = i;
                else end = i;
                numCnt++;
            }
            i++;
        }        

        ways += i + (end - start);
        q.push(i);

        while(i < n) {
            q.push(nums[i]);
            end = i;
            if(nums[i] != 0) {
                while(q.front() == 0 && start < i) {
                    q.pop();
                    start++;
                }
                q.pop();
                start++;
            }
            // cout << nums[start] << "    " << endl;
            ways += start + 1;
            q.push(i);
            i++;
        }

    }

    cout << ways;

    return 0;
}