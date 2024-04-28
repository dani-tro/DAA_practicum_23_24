#include<bits/stdc++.h>
const int MAXN = 10e5;
int n;
int m;
long long k;
long long len = 0;
// struct Event{
//     int type;
//     int value;
//     bool operator<(const Event& other){
//         if(this->value < other.value || (this->value == other.value && this->type > other.type)){
//             return true;
//         }
//         return false;
//     }
// };
struct Triple{
    long long value_to_decrease;
    long long visits;
    bool operator<(const Triple& other){
        if(this->visits < other.visits || (this->visits == other.visits && this->value_to_decrease < other.value_to_decrease)){
            return true;
        }
        return false;
    }
};
Triple arr[MAXN];
//Event vis[MAXM];

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
    for(int i = 0; i < m; i++){
        int left, right;
        std::cin >> left >> right;
        left--;
        for(left; left < right;left++){
            arr[left].visits++;
            len += arr[left].value_to_decrease;
            //std::cout << len << '!' << std::endl;
        }

    }
    
    std::sort(arr, arr + n);
    int step = n - 1;
    //std::cout << len << std::endl;
    while(k > 0 && step >= 0){
        if(arr[step].value_to_decrease == 0 || arr[step].visits == 0){
            step--;
        }else{
            if(k <= arr[step].value_to_decrease){
                len -= k * arr[step].visits;
                break;
            }else{
                len -= arr[step].visits * arr[step].value_to_decrease;
                k -= arr[step].value_to_decrease;
                step--;
            }
        }
    }
    std::cout << len;
    return 0;
}

/*
5 3 5
1 2 3 4 5
1 2
2 3
3 4
*/




// std::sort(vis, vis + 2 * m);
    // int counter = 1;
    // int cut = arr[0].value_to_decrease - 1;
    // for(int i = 1; i < 2 * m; i++){
    //     if(vis[i].type == 1){
    //         if(vis[i].value != vis[i - 1].value){
    //             for(cut; cut < vis[i].value - 1; cut++){
    //                 arr[cut].visits += counter;
    //                 len += counter * arr[cut].value_to_decrease;
    //             }
    //         }
    //         counter++;
    //     }else{
    //         if(vis[i].value == vis[i - 1].value){
    //             for(cut; cut <= vis[i].value - 1; cut++){
    //                 arr[cut].visits += counter;
    //                 len += counter * arr[cut].value_to_decrease;
    //             }
    //         }
    //         for(cut; cut < vis[i].value - 1; cut++){
    //             arr[cut].visits += counter;
    //             len += counter * arr[cut].value_to_decrease;
    //         }
    //         counter--;
    //     }
    //     // if(vis[i].type == 1 && vis[i].value == vis[i - 1].value){
    //     //     counter++;
    //     // }
    //     // if(vis[i].type == 1){
    //     //     if(vis[i].value != vis[i - 1].value){
    //     //         for(cut; cut < vis[i].value - 1; cut++){
    //     //             std::cout << cut << ' ' << vis[i].value << '!' << std::endl;
    //     //             arr[cut].visits += counter;
    //     //             len += counter * arr[cut].value_to_decrease;
    //     //             std::cout << len << std::endl;
    //     //         }
    //     //         cut--;
    //     //     }
    //     //     counter++;
    //     // }else{
    //     //     for(cut; cut <= vis[i].value; cut++){
    //     //         arr[cut].visits += counter;
    //     //         len += (counter) * arr[cut].value_to_decrease;
    //     //         std::cout << len << '@' << std::endl;
    //     //     }
    //     //     counter--;
    //     // }
    // }
    // for(int i = 0; i < n; i++){
    //     std::cout << arr[i].value_to_decrease << ' ' << arr[i].visits << std::endl;
    // }