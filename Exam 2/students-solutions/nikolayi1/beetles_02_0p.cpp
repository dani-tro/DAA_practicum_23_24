#include <iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAXN = 1000;
int coords[MAXN][2];
size_t prices[MAXN][MAXN];
size_t best[MAXN];


int prc(int a, int b) {
	return (coords[a][0] - coords[b][0]) * (coords[a][0] - coords[b][0]) + 
		(coords[a][1] - coords[b][1]) * (coords[a][1] - coords[b][1]);
}

void addPrc(int a, int b) {
	prices[a][b] = prc(a, b);
	prices[b][a] = prc(a, b);
	//cout << a << " to " << b << " : " << prc(a, b) << endl;
}

int main() {
	int i, j, n;
	
	size_t sum = 0;
	cin >> n;
	//int* best = new int[n];

	for (i = 0; i < n; ++i) {
		cin >> coords[i][0] >> coords[i][1];
		for (j = i - 1; j >= 0; --j) {
			addPrc(i, j);
		}
	}

	for (i = 0; i < n; ++i) {
		best[i] = prices[0][i];
	}

	//best = prices[0];
	best[0] = 0;
	int min_ind = 1, last = 0;

	for (i = 0; i < n - 1; ++i) {
		for (j = 0; j < n; ++j) {
			if(prices[last][j] < best[j]) {
				best[j] = prices[last][j];
			}
		}

		for (j = 0; j < n; ++j) {
			if (best[j] != 0) {
				min_ind = j;
				break;
			}
		}

		for (j = 1; j < n; ++j) {
			if (best[j] != 0 && best[j] < best[min_ind]) {
				min_ind = j;
			}
		}

		/*if (best[min_ind] <= 0) {
			cout << "error" << endl;
		}*/

		sum += best[min_ind];
		best[min_ind] = 0;
		last = min_ind;
	}

	cout << sum;


	return 0;
}