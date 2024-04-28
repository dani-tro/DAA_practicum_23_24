    #include <bits/stdc++.h>
        using namespace std;
    
        const long long SIZE = 1'000'000;
        long long repeats[SIZE];
        long long  N,M,K;
        long long original[SIZE];
        long long arr[SIZE];
        int l[SIZE];
        int r[SIZE];

        void print(long long arr[],int size){
        for (size_t i = 0; i < size; i++) {
            cout << arr[i] << " ";
        } 
        cout <<endl;
        }
        int main() {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            cin >> N >> M>>K;
            for (size_t i = 0; i < N; i++){
                int a;
                cin >> a;
                arr[i] = a;
                original[i] = a;
            }
            for (size_t i = 0; i < M; i++){
                int a,b;
                cin >> a>>b;
                for (size_t i = a - 1; i <= b - 1; i++)
                      repeats[i]++;
            }
            for (size_t i = 0; i < N; i++) {
                arr[i] =  arr[i] * repeats[i];
            }
            for (size_t i = 0; i < K; i++) {
                int max = arr[0];
                int maxIndex = 0;
                for (size_t k = 1; k < N; k++) {
                    if (arr[k] >= max) {
                        max = arr[k];
                        maxIndex = k;
                    }
                }
                if (max <= 0) break;  
                arr[maxIndex] =(--original[maxIndex]) * repeats[maxIndex];
            }
            int sum = 0;
            for (size_t i = 0; i < N; i++) {
                sum +=arr[i];
            }
            cout<< sum;
            
        
        }