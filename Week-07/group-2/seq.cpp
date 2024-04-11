#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> A(n + 1), left(n + 1), right(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> A[i];
    }
    {
        stack<int> st;
        for(int i = 1; i <= n; i ++){
            while(!st.empty() && A[st.top()] <= A[i]){
                st.pop();
            }
            left[i] = (st.empty() ? 0 : st.top());
            st.push(i);
        }
    }
    {
        stack<int> st;
        for(int i = n; i >= 1; i --){
            while(!st.empty() && A[st.top()] <= A[i]){
                st.pop();
            }
            right[i] = (st.empty() ? 0 : st.top());
            st.push(i);
        }
    }
    int T; cin >> T;
    for(int i = 0; i < T; i ++){
        int k; cin >> k;
        cout << left[k] << " " << right[k] << endl;
    }
}
/*
10
6 5 5 4 2 4 8 5 3 6
4
1 4 7 8
*/
