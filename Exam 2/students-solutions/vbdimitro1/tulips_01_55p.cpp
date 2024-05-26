#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;

	vector<vector<int>> arr(N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int buff;
			cin >> buff;
			arr[i].push_back(buff);
		}

	int result = N * M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i + 1 < N && arr[i][j] == arr[i + 1][j])
				result--;
			if (j + 1 < M && arr[i][j] == arr[i][j + 1])
				result--;
		}
	}

	cout << result;

	return 0;
}