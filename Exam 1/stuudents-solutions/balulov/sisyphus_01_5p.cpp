#include <iostream>
#include <algorithm>
#include <vector>

std::vector<long long int> commonIndex(std::vector<long long int> mountain, std::vector<std::pair<long long int,long long int>> moves) {
	//int arrSize = mountain.size();
	int* array = new int[mountain.size()];

	for (int i = 0; i < mountain.size(); ++i) {
		array[i] = 0;
	}
	for (int i = 0; i < moves.size(); ++i) {
		for (int j = moves[i].first - 1; j < moves[i].second; ++j) {
			array[j]++;
		}
	}
	std::vector<long long int> maxIndex;
	long long int max = array[0];
	for (int i = 0; i < mountain.size(); ++i) {
		if (max <= array[i]){
			max = array[i];
		}
	}

	for (int i = 0; i < mountain.size(); ++i) {
		if (max == array[i]) {
			maxIndex.push_back(i + 1);
		}
	}
	
	delete[] array;
	return maxIndex;
}


int main() {
	long long int N; //redicata
	long long int K; //broi tyrkalqniq
	long long int M; //maksimalni namalqvaniq
	long long int l;
	long long int r;
	long long int current;
	std::cin >> N;
	std::cin >> K;
	std::cin >> M;

	std::vector<long long int> mountain;
	std::vector<std::pair<long long int,long long int>> moves;

	for (int i = 0; i < N; ++i) {
		std::cin >> current;
		mountain.push_back(current);
	}

	for (int i = 0; i < K; ++i) {
		std::cin >> l;
		std::cin >> r;
		std::pair<int, int> curr = std::make_pair(l,r);
		moves.push_back(curr);
	}
	
	std::vector<long long int> maxIndex = commonIndex(mountain, moves);
	std::vector<std::pair<long long int, long long int>> commons;
	std::vector<long long int> comms;
	
	for (int i = 0; i < maxIndex.size(); ++i) {
		comms.push_back(mountain[maxIndex[i] - 1]);
	}
	
	for (int i = 0; i < comms.size(); ++i) {
		commons.push_back(std::make_pair(maxIndex[i], comms[i]));
	}
	
	std::sort(commons.begin(), commons.end());
	
	
	for (int i = commons.size() - 1; i >= 0; --i) {
		while ((K > 0) && (commons[i].second > 0)) {
			commons[i].second--;
			K--;
		}
		if (K <= 0) {
			break;
		}
	}
	
	long long int sum = 0;
	for (int i = 0; i < moves.size(); ++i) {
		for (int j = moves[i].first - 1; j < moves[i].second; ++j) {
			sum += mountain[j];
		}
	}

	std::cout << sum;
	return 0;
}