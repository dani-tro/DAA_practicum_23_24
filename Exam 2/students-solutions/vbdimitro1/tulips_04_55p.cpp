#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 100000;

struct coord
{
	int x;
	int y;

	coord(int newX, int newY)
	{
		x = newX;
		y = newY;
	}

	coord()
	{
		x = 0;
		y = 0;
	}

	bool operator<(const coord& other)const
	{
		return x > other.x;
	}
};

const int MAXX = 1000001;
const int MAXY = 11;

coord parent[MAXX][MAXY];
int sz[MAXX][MAXY];

void make_set(int x, int y)
{
	parent[x][y] = { x,y };
	sz[x][y] = 1;
}

coord find_set(int x, int y)
{
	if (parent[x][y].x == x && parent[x][y].y == y)
		return parent[x][y];

	return parent[x][y] = find_set(parent[x][y].x, parent[x][y].y);
}

void union_sets(int x1, int y1, int x2, int y2)
{
	coord C1 = find_set(x1, y1);
	coord C2 = find_set(x2, y2);
	x1 = C1.x;
	y1 = C1.y;
	x2 = C2.x;
	y2 = C2.y;

	if (x1 == x2 && y1 == y2)
	{
		return;
	}

	if (sz[x1][y1] < sz[x2][y2])
	{
		swap(x1, x2);
		swap(y1, y2);
	}

	parent[x2][y2].x = x1;
	parent[x2][y2].y = y1;

	sz[x1][y1] += sz[x2][y2];
}

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
			make_set(i, j);
        }

    long long result = N * M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
			coord fsij = find_set(i, j);
			coord fsi1j = find_set(i+1, j);
			coord fsij1 = find_set(i, j+1);

            if (i + 1 < N && (fsij.x != fsi1j.x || fsij.y != fsi1j.y) && arr[i][j] == arr[i + 1][j])
			{
				result--;
				union_sets(i, j, i + 1, j);
			}
            if (j + 1 < M && (fsij.x != fsij1.x || fsij.y != fsij1.y) && arr[i][j] == arr[i][j + 1])
			{
				result--;
				union_sets(i, j, i, j + 1);
			}
        }
    }

    cout << result;

    return 0;
}