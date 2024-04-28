    #include <bits/stdc++.h>
        using namespace std;
    
        const long long SIZE = 10000000;
        long long  N,M,K;
        long long arr[SIZE];
        bool hasTV[SIZE];

        void print(long long arr[],int size){
        for (size_t i = 0; i < size; i++) {
            cout << arr[i] << " ";
        } 
        cout <<endl;
        }
        int biggestIndexNoTV() {
            int max = 0;
            int maxEl = arr[0];
            for (size_t i = 1; i < N-1; i++) {
                if(arr[i] > max && !hasTV[i]) {
                    max = i;
                    maxEl = arr[i];
                }
            }
            return max;
        }
        int main() {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            cin >> N >>K;
            for (size_t i = 0; i < N-1; i++){
                cin >> arr[i];
            }
            for (size_t i = 0; i < K; i++) {
                int index = biggestIndexNoTV();
                hasTV[index] = true;
            }
            int temp = 0;
            int max = 0;
            for (size_t i = 0; i < N; i++) {
                if (!hasTV[i]) {
                    temp += arr[i];
                } else {
                    max = std::max(max,temp);
                    temp = 0;
                }
            }
            
            cout << max;
            



        }

