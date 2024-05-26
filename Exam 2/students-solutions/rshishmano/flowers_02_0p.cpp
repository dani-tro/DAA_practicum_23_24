#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

bool canMergeWithoutDuplicatesAndKeepOrder(const std::vector<std::vector<int>>& arrays, std::vector<int>& mergedArray) {
    std::unordered_set<int> seenElements;
    std::unordered_map<int, int> lastPosition;

    for (const auto& array : arrays) {
        for (size_t i = 0; i < array.size(); ++i) {
            lastPosition[array[i]] = i;
        }
    }
    for (const auto& array : arrays) {
        for (size_t i = 0; i < array.size(); ++i) {
            int element = array[i];
            if (seenElements.find(element) != seenElements.end()) {
                continue;
            }
            bool canPlace = true;
            for (size_t j = i + 1; j < array.size(); ++j) {
                if (seenElements.find(array[j]) != seenElements.end()) {
                    canPlace = false;
                    break;
                }
            }
            if (canPlace) {
                mergedArray.push_back(element);
                seenElements.insert(element);
            }
        }
    }
    return true;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    size_t K;
    std::cin >> K;

    std::vector<std::vector<int>> arrays(K);

    for(size_t i = 0; i < K; ++i){

        size_t N;
        std::cin >> N;

        for(size_t j = 0; j < N; ++j){

            int number;
            std::cin >> number;

            arrays[i].push_back(number);

        }

    }

    std::vector<int> mergedArray;

    if (canMergeWithoutDuplicatesAndKeepOrder(arrays, mergedArray)) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }

    return 0;
}