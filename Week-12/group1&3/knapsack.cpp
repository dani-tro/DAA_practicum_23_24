#include <iostream>
using namespace std;
#define MAX 1000

int N, M, weight[MAX], value[MAX], F[MAX][MAX];

void fill_F()
{
	for(int j = 0; j <= M; j++) F[0][j] = 0;
	for(int i = 1; i <= N; i++) F[i][0] = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			if(weight[i] <= j) 
				F[i][j] = max(F[i - 1][j], 
							  F[i - 1][j - weight[i]] + value[i]);
			else F[i][j] = F[i - 1][j];
		}
	}
}

void find_solution()
{
	int j = M;
	for(int i = N; i >= 1; i--)
	{
		if(F[i][j] != F[i - 1][j])
		{
			cout << i << " ";
			j = j - weight[i];
		}
	}
	cout << endl;
}

int main()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> weight[i];
	for(int i = 1; i <= N; i++) cin >> value[i];
	fill_F();
	cout << F[N][M] << endl;
	find_solution();
	return 0;
}

