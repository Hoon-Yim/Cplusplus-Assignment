/*
 * Last Update : Dec 03 2020
 * Problem : 1926(acmicpc) Picture / 그림
 * Link : https://www.acmicpc.net/problem/1926
 */

#include <iostream>
#include <utility>
#include <queue>

/*
 * BFS 과정은 아래로 구성되어 있다
 *
 * 현재 위치를 큐의 맨 아래로 가도록 저장한다
 * 현재 위치를 기준으로 사방팔방을 살핀 후 원하는 조건에 맞으면 큐에 저장한다
 * 모두 저장하였으면 큐의 맨 아래에 있는 값을 버리고 위에서 저장했던 값이 자동으로 큐 맨 아래로 이동한다
 * 그 값을 기준으로 또 사방팔방을 체크한다
 *
 * 위의 연산을 계속해서 반복한다
 */

int board[502][502];
bool vis[502][502];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    int x, y; std::cin >> x >> y;
    int paint_num = 0, max = 0;

    for(int i = 0; i < x; ++i)
        for(int j = 0; j < y; ++j)
            std::cin >> board[i][j];

    for(int i = 0; i < x; ++i)
    {
        for(int j = 0; j < y; ++j)
        {
            if(board[i][j] == 0 || vis[i][j]) continue;
            paint_num++;
            int area = 0;
            vis[i][j] = true;
            std::queue<std::pair<int, int>> Q;
            Q.push({i, j});

            while(!Q.empty())
            {
                area++;
                std::pair<int, int> cur = Q.front(); Q.pop();

                for(int dir = 0; dir < 4; ++dir)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
            max = std::max(max, area);
        }
    }
    std::cout << paint_num << "\n" << max;
}