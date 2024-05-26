#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 10000;

vector<long long int> friends[MAX];
vector<long long int> graph[MAX];


long long int k, c, f;

bool dfs(vector<long long int> gr[], long long int start, long long int value) {
	std::cout << "HEY";
	if (start == value) {
		return true;
	}
	
	for (int i = 0; i < gr->size(); ++i) {
		if (!gr[i].empty()) {
			for (int j = 0; j < gr[i].size(); ++j) {
				std::cout << gr[i][j] << " ";
				std::cout << value;
				std::cout << std::endl;
				dfs(gr, gr[i][j], value);
			}
		}
	}

	return false;
}

bool possibleGarden(vector<long long int> gr[]) {
	for (int i = 0; i < gr->size(); ++i) {
		if (!gr[i].empty()) {
			for (int j = 0; j < gr[i].size(); ++j) {
				for (int k = 0; k < gr[i].size(); ++k) {
					if (dfs(gr, gr[i][k], gr[i][j]) && dfs(gr, gr[i][j], gr[i][k]) && (gr[i][k] != gr[i][j])) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> c;
		for (int j = 0; j < c; ++j) {
			cin >> f;
			friends[i].push_back(f);
		}
	}

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < friends[i].size(); ++j) {
			for (int k = 0; k < friends[i].size(); ++k) {
				if (friends[i][j] != friends[i][k]) {
					if (j > k) {
						graph[friends[i][j]].push_back(friends[i][k]);
					}
				}
			}
		}
	}

	std::cout << possibleGarden(graph);
	
	return 0;
}