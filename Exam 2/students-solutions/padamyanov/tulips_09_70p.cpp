#include <iostream>
using namespace std;
struct Pair {
    Pair()
    {
        x = 0;
        y = 0;
    }
    Pair(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int x;
    int y;
};
size_t matrix[1000][1000];
Pair groups[100000];
int n, m;
size_t groupSize;
bool contains(int x, int y)
{
    for (size_t i = 0; i < groupSize; i++)
    {
        if (groups[i].x == x && groups[i].y == y)
        {
            return true;
        }
    }
    return false;
}
void addToGroup(int x, int y)
{
    groups[groupSize++] = Pair{ x, y };
    //if (matrix[x][y] == 5) cout << x << " " << y << endl;

    if (x + 1 < n && !contains(x + 1, y) && matrix[x][y] == matrix[x + 1][y])
    {
        addToGroup(x + 1, y);
    }
    if (x > 0 && !contains(x - 1, y) && matrix[x][y] == matrix[x - 1][y])
    {
        addToGroup(x - 1, y);
    }
    if (y + 1 < m && !contains(x, y + 1) && matrix[x][y] == matrix[x][y + 1])
    {
        addToGroup(x, y + 1);
    }
    if (y > 0 && !contains(x, y - 1) && matrix[x][y] == matrix[x][y - 1])
    {
        addToGroup(x, y - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t answer = 0;
    groupSize = 0;

    cin >> n >> m;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (!contains(i, j))
            {
                //cout << i << " " << j << endl;
                addToGroup(i, j);
                answer++;

            }

        }
    }

    cout << answer;
    //for (size_t i = 0; i < n; i++)
    //{
    //    for (size_t j = 0; j < m; j++)
    //    {
    //        cout << matrix[i][j] << " ";
    //    }
    //    cout << endl;
    //}

}