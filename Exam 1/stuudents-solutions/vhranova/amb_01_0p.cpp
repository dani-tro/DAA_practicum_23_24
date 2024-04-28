#include<iostream>
#include<vector>


//input: 
// 4 2
// 3 5 2

long long findLongestDistances(std::vector<long long> distances, long long tvS) {
	long long apartments = distances.size() + 1;
	if (tvS >= (apartments / 3) && tvS < apartments) return distances[0];
	else if (tvS < apartments) {
		return apartments / (tvS + 1) * distances[0];
	}
}
int main() {
	long long apartaments, tvS,element;
	std::cin >> apartaments >> tvS;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::vector<long long> distances;
	while (apartaments != 1) {
		std::cin >> element;
		distances.push_back(element);
		apartaments--;
	}
	long long result = findLongestDistances(distances, tvS);
	std::cout << 10 / 3;

}