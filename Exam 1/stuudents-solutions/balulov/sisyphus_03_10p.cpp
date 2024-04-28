#include <iostream>
#include <algorithm>
#include <vector>

std::pair<std::vector<long long int>,long long int> commonIndex(std::vector<long long int> mountain, std::vector<std::pair<long long int,long long int>> moves) {
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
	return std::make_pair(maxIndex, max);
}

std::vector<long long int> setIndex(std::vector<long long int> mountain, std::vector<std::pair<long long int, long long int>> moves, int m) {
	int* array = new int[mountain.size()];

	for (int i = 0; i < mountain.size(); ++i) {
		array[i] = 0;
	}
	for (int i = 0; i < moves.size(); ++i) {
		for (int j = moves[i].first - 1; j < moves[i].second; ++j) {
			array[j]++;
		}
	}
	std::vector<long long int> setIndex;
	for (int i = 0; i < mountain.size(); ++i) {
		if (array[i] == m) {
			setIndex.push_back(array[i]);
		}
	}

	delete[] array;
	return setIndex;
}

long long int findMaxIndex(std::vector<long long int> vec) {
	long long int max = vec[0];
	long long int maxIndex = 0;
	for (int i = 0; i < vec.size(); ++i) {
		if (max <= vec[i]) {
			max = vec[i];
			maxIndex = i;
		}
	}
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
	long long int maxIter = commonIndex(mountain, moves).second;
	std::vector<long long int> maxIndex = commonIndex(mountain, moves).first;
	while ((K > 0) && (maxIter > 0)) {
		std::vector<long long int> currMost = setIndex(mountain, moves, maxIter);
		std::vector<std::pair<long long int, long long int>> commons;
		std::vector<long long int> comms;
		
		for (int i = 0; i < currMost.size(); ++i) {
			long long int currMaxIndex = findMaxIndex(currMost);
			long long int foundIndex = 0;
			for (int j = 0; j < mountain.size(); ++j) {
				if (currMost[currMaxIndex] = mountain[j]) {
					foundIndex = j;
				}
			}
			if (mountain[foundIndex] == 0) {
				break;
			}
			else {
				mountain[foundIndex]--;
				K--;
			}
		}
		maxIter--;
	}
	/*
	for (int i = 0; i < mountain.size(); ++i) {
		std::cout << mountain[i];
	}
	*/
	
	long long int sum = 0;
	for (int i = 0; i < moves.size(); ++i) {
		for (int j = moves[i].first - 1; j < moves[i].second; ++j) {
			sum += mountain[j];
		}
	}

	std::cout << sum;
	return 0;
}
