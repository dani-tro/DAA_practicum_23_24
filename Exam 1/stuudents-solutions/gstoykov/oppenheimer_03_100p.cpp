    #include <bits/stdc++.h>
        using namespace std;
    
        const long long SIZE = 1'000'000;
        long long  N;
        long long  K,S;
        long long arr[SIZE];

       void print(long long arr[],int size){
        for (size_t i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
       }
        int main() {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            cin >> N >> K;
            for (size_t i = 0; i < N; i++)
                cin >> arr[i];
            sort(arr,arr+N);
            int i = 0;
            int j = 0;
            int temp = 0;
            int max = 0;
            while (i<N && j<N) {
                if (arr[j] - arr[i] <=K) {
                    j++;
                    temp++;
                } else {
                    i++;
                    max = max < temp ? temp : max;
                    temp--;
                }
            }
            cout << (max > temp ? max : temp);
            
        }