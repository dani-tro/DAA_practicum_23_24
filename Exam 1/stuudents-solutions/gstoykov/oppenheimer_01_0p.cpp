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
        bool can_be_taken(int count) {
            for (size_t i = 0; i < N; i++) {
                
                if (i+count-1 < N && arr[i+count-1] - arr[i] <=K) {
                    return true;
                }
            }
            return false;
            
        }
        int main() {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            cin >> N >> K;
            for (size_t i = 0; i < N; i++)
                cin >> arr[i];
            sort(arr,arr+N);
            int l = 0;
            int r = N - 1;
            while(l < r) {
                int mid = (l+r) / 2;
                if (can_be_taken(mid)) {
                    l = mid;
                } else {
                    r = mid-1;
                }
            }
            cout << r;
            
        }