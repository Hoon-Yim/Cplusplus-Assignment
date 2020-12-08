/*
 * Last Update : Dec 07 2020
 * Problem : 7576(acmicpc) Tomato / 토마토
 * Link : https://www.acmicpc.net/problem/7576
 */

#include <iostream>
#include <queue>
#include <utility>

int board[1002][1002];
int V[1002][1002];
int dx[4]{1, 0, -1, 0};
int dy[4]{0, 1, 0, -1};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int m, n; std::cin >> m >> n;
    std::queue<std::pair<int, int>> Q;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            std::cin >> board[i][j];
            if(board[i][j] == 1)
                Q.push({i, j});
            else if(board[i][j] == 0)
                V[i][j] = -1;
        }

    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int dirX = cur.first + dx[dir];
            int dirY = cur.second + dy[dir];
            if(dirX < 0 || dirY < 0 || dirX >= n || dirY >= m) continue;
            if(V[dirX][dirY] >= 0) continue;
            V[dirX][dirY] = V[cur.first][cur.second] + 1;
            Q.push({dirX, dirY});
        }
    }

    int result = 0;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            if(V[i][j] == -1)
            {
                std::cout << -1;
                return 0;
            }
            result = std::max(result, V[i][j]);
        }

    std::cout << result;
}