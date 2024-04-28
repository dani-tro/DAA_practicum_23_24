    #include <bits/stdc++.h>
        using namespace std;
       
        
        const long long SIZE = 1'000'000;
        double m;
        long long  N;
        long long  K,S;
        pair<pair<double,double>,int> arr[SIZE];
        double amount[SIZE];

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
            cin >> m;
            cin >> N;
            for (size_t i = 0; i < N; i++) {
                cin >> arr[i].first.first >> arr[i].first.second;
                arr[i].second = i;
            }
            double remaining = m;
            double sum = 0;
            sort(arr,arr+N,[](pair<pair<double,double>,int>a,pair<pair<double,double>,int>b) {
                    if (a.first.second ==b.first.second) {
                        return a.first.first < b.first.first;
                    }
                    return a.first.second > b.first.second;
            });
            for (size_t i = 0; i < N; i++) {
                if (remaining >= arr[i].first.first) {
                    remaining -=arr[i].first.first;
                    sum += arr[i].first.first * arr[i].first.second;
                    amount[arr[i].second] = arr[i].first.first;
                } else {
                    sum += remaining * arr[i].first.second;
                    amount[arr[i].second] = remaining;
                    break;
                }
            }
            cout << fixed << setprecision(2) <<  sum<<endl;
            for (size_t i = 0; i < N; i++) {
                cout << fixed << setprecision(3) << amount[i] << endl;
            }
        }