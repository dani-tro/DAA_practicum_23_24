#include<bits/stdc++.h>
const int MAXN = 10e5;
const int MAXM = 2 * 10e6;
int n;
int m;
long long k;
int len = 0;
struct Event{
    int type;
    int value;
    bool operator<(const Event& other){
        if(this->value < other.value || (this->value == other.value && this->type > other.type)){
            return true;
        }
        return false;
    }
};
struct Triple{
    int value_to_decrease;
    int visits;
    bool operator<(const Triple& other){
        if(this->visits < other.visits || (this->visits == other.visits && this->value_to_decrease < other.value_to_decrease)){
            return true;
        }
        return false;
    }
};
Triple arr[MAXN];
Event vis[MAXM];
int main(){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int temp;
        std::cin >> temp;
        arr[i] = {temp, 0};

    }
    for(int i = 0; i < 2 *  m; i+=2){
        int left, right;
        std::cin >> left >> right;
        vis[i] = {1, left};
        vis[i + 1] = {-1, right};

    }
    std::sort(vis, vis + 2 * m);
    // for(int i = 0; i < 2 * m; i++){
    //     std::cout << vis[i].type << ' ' << vis[i].value<< std::endl;
    // }
    int counter = 0;
    int cut = 0;
    for(int i = 0; i < 2 * m; i++){
        if(vis[i].type == 1){
            if(vis[i].value != vis[i + 1].value){
                for(cut; cut < vis[i + 1].value - 1; cut++){
                    arr[cut].visits += counter + 1;
                    len += (counter + 1) * arr[cut].value_to_decrease;
                }
            }
            counter++;
        }else{
            for(cut; cut <= vis[i].value; cut++){
                arr[cut].visits += counter;
                len += (counter) * arr[cut].value_to_decrease;
            }
            counter--;
        }
    }
    std::sort(arr, arr + n);
    // for(int i = 0; i < n; i++){
    //     std::cout << arr[i].value_to_decrease << ' ' << arr[i].visits << std::endl;
    // }
    int step = n - 1;
    while(k && step){
        if(arr[step].value_to_decrease == 0){
            step--;
        }else{
            if(k <= arr[step].value_to_decrease){
                len -= k * arr[step].visits;
                break;
            }else{
                len -= arr[step].visits * arr[step].value_to_decrease;
                k -= arr[step].visits;
                step--;
            }
        }
    }
    std::cout << len;
    // int step = 0;
    // for(int i = 0; i < together; i++){
    //     if(arr[i].type == 0){
    //         answers[step] = {arr[i].value, counter};
    //         len += arr[i].value * counter;
    //         step++;
    //     }else if(arr[i].type == 1){
    //         counter++;
    //     }else{
    //         counter--;
    //     }
    // }
    // std::sort(answers, answers + step);
    // step--;
    // for(step; step >=0; step--){
    //     if(k <= arr[step].visits){
    //         len -= arr[step]
    //     }
    // }
    return 0;
}