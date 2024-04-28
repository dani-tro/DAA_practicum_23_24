#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minMaxDistance(int N, int K, vector<int>& distances) {
    sort(distances.begin(), distances.end());
    int sum = 0;
    for (int i = 0; i < K - 1; ++i) {
        sum += distances[i];
    }
    return sum;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> distances(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> distances[i];
    }

    cout << minMaxDistance(N, K, distances) << endl;

    return 0;
}
