#include<iostream>
#include<vector>
using namespace std;
#define MAX 1005
int matrix[MAX][MAX];

int n, m;
int beetleCount = 0;

bool is_diferent(int x, int y) {
  return x<n && y<m && matrix[x][y] != matrix[x][y+1] && matrix[x][y] != matrix[x+1][y]
        || x == n && y<m && matrix[x][y] != matrix[x][y+1]
        || x < n && y == m && matrix[x][y] != matrix[x+1][y]
        || x == n && y == m;
}

int beetles(int row, int col) {
  if(row >= n || col >= m) return 0;
  else if(row == n-1 && col == m-1) return 1;

  if(matrix[row][col] == -1) return 0;
  //cout << "currently at: " << row << col << endl;
  
  int ans = 0;  

  if(is_diferent(row, col)) {
    //cout << ans << "beetles at: " << row << col << endl;
    ++ans;
  }

  if(matrix[row][col] == matrix[row][col+1]) {
    matrix[row][col] = -1;
    beetles(row, col+1);
  }
  
  if(matrix[row][col] == matrix[row+1][col]) {
    matrix[row][col] = -1;
    beetles(row+1, col);
  }

  //matrix[row][col] = -1;

  return ans + beetles(row, col+1) + beetles(row+1, col);
  
}

int count_matrix() {
  int count = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      if(matrix[i][j] != -1) ++count;
    } 
  }

  return count;
}

void print_matrix() {
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      cout << matrix[i][j] << ' ';
    } 
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      cin >> matrix[i][j];
    }
  }
  
  beetles(0, 0);
  cout << count_matrix();
  //print_matrix();
}