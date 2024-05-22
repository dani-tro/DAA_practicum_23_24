#include <iostream>
using namespace std;
#define MAX 1000

int N, M, weight[MAX], value[MAX], F[2][MAX];

void fill_F()
{
	for(int j = 0; j <= M; j++) F[0][j] = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			if(weight[i] <= j) 
				F[i % 2][j] = max(F[(i + 1) % 2][j], 
							  F[(i + 1) % 2][j - weight[i]] + value[i]);
			else F[i % 2][j] = F[(i + 1) % 2][j];
		}
	}
	return;
}

int main()
{
	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> weight[i];
	for(int i = 1; i <= N; i++) cin >> value[i];
	fill_F();
	cout << F[N % 2][M] << endl;
	return 0;
}

