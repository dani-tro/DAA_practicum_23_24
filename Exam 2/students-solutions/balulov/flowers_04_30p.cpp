#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 20000;

vector<long long int> friends[MAX];
vector<long long int> graph[MAX];
bool visited[MAX];
bool fin;

long long int k, c, f;

void dfs(vector<long long int> gr[], long long int start, long long int curr, int count) {
	
	for(int i = 0; i < gr[start].size(); ++i){
		if (!visited[gr[start][i]]) {
			if ((gr[start][i] == curr)) {
				fin = true;
			}
			visited[gr[start][i]] = true;
			dfs(gr, gr[start][i], curr, count++);
		}
	}
}

bool possibleGarden(vector<long long int> gr[]) {
	for (int i = 0; i < MAX; ++i) {
		if (!gr[i].empty()) {
			for (int j = 0; j < gr[i].size(); ++j) {
				dfs(gr, gr[i][j], gr[i][j], 0);
				if (fin) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	for (int i = 0; i < MAX; ++i) {
		visited[i] = false;
	}
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