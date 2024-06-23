#include<iostream>
#include<algorithm>
const int MAXN = 1e5 + 2;
const long long INF = 1e17 * 2;
long long n, m, i, j, left, right, middle, s, w, answer;
int start[MAXN];
int work[MAXN];

bool calc(){
    s = 0;
    for(i = 0; i < n; i++){
        if(middle >= start[i]){
            s += (middle - start[i]) / work[i];
        }
       
    }
    if(s >= m){
        return true;
    }
    return false;
}
int main(){
    std::cin >> n >> m;
    for(i = 0; i < n; i++){
        std::cin >> work[i] >> start[i];
    }
    // std::sort(start, start + n);
    // std::sort(work, work + n);

    left = 1;
    right = INF;
    while(left <= right){
        middle = left + (right - left) / 2;
        if(calc()){
            answer = middle;
            right = middle - 1;
        }else{
            left = middle + 1;
        }
    }
    std::cout << answer;
}