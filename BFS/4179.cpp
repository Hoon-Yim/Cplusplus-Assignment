/*
 * Last Update : Dec 07 2020
 * Problem : 4179(acmicpc) Fire! / 불!
 * Link : https://www.acmicpc.net/problem/4179
 */

/*
 * #으로 된 벽들은 불, 지훈이 둘다 못지나감
 * 지훈이 = J, 불 = F
 * . 들은 불, 지훈이 둘다 지나갈 수 있음
 *
 * BFS를 지훈이와 불 둘다 돌려서 비교를 해야할 듯 하다
 *
 * TODOS:
 * 지훈이와 불 둘 다 BFS를 돌리기 위해 서로 다른 V 변수가 필요
 * Q또한 2개가 필요
 * 스트링 배열로 board 입력받기
 *
 * 시작점 찾기 f, v
 */


#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

std::string board[1002];
int VF[1002][1002];
int VJ[1002][1002];
int dx[4]{1, 0, -1, 0};
int dy[4]{0, 1, 0, -1};

int main()
{
    int r, c; std::cin >> r >> c;
    std::queue<std::pair<int, int>> F;
    std::queue<std::pair<int, int>> J;


    for(int i = 0; i < r; ++i)
        std::cin >> board[i];

    for(int i = 0; i < r; ++i)
    {
        std::fill(VF[i], VF[i] + c, -1);
        std::fill(VJ[i], VJ[i] + c, -1);
    }

    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
        {
            if(board[i][j] == 'J')
            {
                J.push({i, j});
                VJ[i][j] = 0;
            }
            else if(board[i][j] == 'F')
            {
                F.push({i, j});
                VF[i][j] = 0;
            }
        }

    // Fire
    while(!F.empty())
    {
        auto cur = F.front(); F.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(VF[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            VF[nx][ny] = VF[cur.first][cur.second] + 1;
            F.push({nx, ny});
        }
    }

    while(!J.empty())
    {
        auto cur = J.front(); J.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c)
            {
                std::cout << VJ[cur.first][cur.second] + 1;
                return 0;
            }
            if(VJ[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(VF[nx][ny] != 1 && VF[nx][ny] <= VJ[cur.first][cur.second] + 1) continue;
            VJ[nx][ny] = VJ[cur.first][cur.second] + 1;
            J.push({nx, ny});
        }
    }

    std::cout << "IMPOSSIBLE";
}