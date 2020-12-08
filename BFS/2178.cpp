/*
 * Last Update : Dec 07 2020
 * Problem : 2178(acmicpc) Maze Search / 미로 탐색
 * Link : https://www.acmicpc.net/problem/2178
 */

#include <iostream>
#include <utility>
#include <vector>
#include <queue>

std::string board[102];
int visited[102][102];
int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int n, m; std::cin >> n >> m;
    for(int i = 0; i < n; ++i)
        std::cin >> board[i];
    for(int i = 0; i < n; ++i)
        std::fill(visited[i], visited[i] + m, -1);

    std::queue<std::pair<int, int>> Q;
    Q.push({ 0, 0 });
    visited[0][0] = 0;

    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();

        for(int direction = 0; direction < 4; ++direction)
        {
            int dir_y = cur.first + dy[direction];
            int dir_x = cur.second + dx[direction];
            if(dir_y < 0 || dir_x < 0 || dir_y >= n || dir_x >= m) continue;
            if(board[dir_y][dir_x] != '1' || visited[dir_y][dir_x] >= 0) continue;
            visited[dir_y][dir_x] = visited[cur.first][cur.second] + 1;
            Q.push({dir_y, dir_x});
        }
    }

    std::cout << visited[n - 1][m - 1] + 1;
}