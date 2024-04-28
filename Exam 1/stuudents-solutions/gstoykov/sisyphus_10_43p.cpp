    #include <bits/stdc++.h>
        using namespace std;
    
        const long long SIZE = 10000000;
        long long repeats[SIZE];
        long long  N,M,K;
        long long original[SIZE];
        long long arr[SIZE];

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
                cin >> original[i];
            }

            for (size_t i = 0; i < M; i++){
                 long long a,b;
                cin >> a>>b;
                for (size_t i = a - 1; i <= b - 1; i++)
                      repeats[i]++;
            }
            for (size_t i = 0; i < N; i++) {
                arr[i] =  original[i] * repeats[i];
            }
            for (size_t i = 0; i < K; i++) {
                long long max =arr[0];
                long long maxInd = 0;
                for (size_t j = 1; j < N; j++) {
                    if(max < arr[j]) {
                        max = arr[j];
                        maxInd = j;
                    }
                }
                    original[maxInd]--;
                    original[maxInd] = std::max(original[maxInd],(long long)0);
                    arr[maxInd] = original[maxInd] * repeats[maxInd];
            }
            long long sum = 0;
            for (size_t i = 0; i < N; i++) {
                sum +=arr[i];
            }
            
            cout << sum;


        }


        //     for (size_t i = 0; i < K; i++) {
        //          long long max = arr[0];
        //          long long maxIndex = 0;
        //         for (size_t k = 1; k < N; k++) {
        //             if (arr[k] > max && original[k] >0) {
        //                 max = arr[k];
        //                 maxIndex = k;
        //             }
        //         }
        //         if (max <= 0) break;  
        //         --original[maxIndex];
        //         arr[maxIndex] =(original[maxIndex]>0 ? original[maxIndex] : 0 ) * repeats[maxIndex];
        //     }
        //     long long sum = 0;
        //     for (size_t i = 0; i < N; i++) {
        //         sum +=arr[i];
        //     }
        //     cout<< sum;
        // }