#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> direction = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

int solution(vector<vector<int>> maps)
{
    int row = maps.size();
    int col = maps[0].size();

    queue<pair<pair<int, int>, int>> q;

    q.push({{0, 0}, 1});
    maps[0][0] = 0;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (x == row - 1 && y == col - 1)
        {
            return dist;
        }

        for (const auto& [dx, dy] : direction)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= row || ny < 0 || ny >= col)
            {
                continue;
            }

            if (maps[nx][ny] == 0)
            {
                continue;
            }

            maps[nx][ny] = 0;
            q.push({{nx, ny}, dist + 1});
        }
    }

    return -1;
}