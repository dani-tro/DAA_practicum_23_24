
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


bool bMATRIX[1000][1000]{false};
int MATRIX[1000][1000];
void dfs2(int i, int j,int n,int m,int curr) {
	bMATRIX[i][j] = true;
	//std::cout << MATRIX[i][j];
	for (short ii = -1; ii < 2; ii=ii+2) {
		
			if ((ii+i) < n && j< m && ii+i >= 0 && j >= 0 && bMATRIX[ii+i][j]==false && MATRIX[ii+i][j]==curr) {
					dfs2(ii+i, j, n, m,curr);
			}
		
	}
	for (short jj = -1; jj < 2; jj=jj+2) {
			if (i < n && j+jj < m && i >= 0 && jj+j >= 0 && bMATRIX[i][jj+j]==false && MATRIX[i][jj+j]==curr) {
					dfs2(i, jj+j, n, m,curr);
			}
		}
	return;

}


int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MATRIX[i][j];
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << bMATRIX[i][j];
		}
	}*/
	int counter = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!bMATRIX[i][j]) {
				counter++;
				dfs2(i, j, n, m, MATRIX[i][j]);
			}
		}
	}
	cout << counter;

}