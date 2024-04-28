    #include <bits/stdc++.h>
        using namespace std;
    
        const long long SIZE = 10000000;
        long long  N,M,K;
        long long arr[SIZE];
        bool hasTV[SIZE];

       
        int main() {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            cin >> N >>K;
            for (size_t i = 0; i < N-1; i++){
                cin >> arr[i];
            }           
            int i = N -1;
            for (size_t k = 0; k < K; k++) {
                hasTV[i--] = true;
            }
            
            int temp = 0;
            int max = 0;
            for (size_t i = 0; i < N-1; i++) {
                if (!hasTV[i]) {
                    temp += arr[i];
                } else {
                    max = std::max(max,temp);
                    temp = arr[i+1];
                }
            }
           
            
            
            cout << std::max(max,temp);
            



        }

