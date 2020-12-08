#include <iostream>
#include <utility>
#include <vector>
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

std::string board[1002];
int VF[1002][1002];
int VJ[1002][1002];
int dx[4]{ 1, 0, -1, 0 };
int dy[4]{ 0, 1, 0, -1 };

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int r, c; std::cin >> r >> c;
    std::queue<std::pair<int, int>> F;
    std::queue<std::pair<int, int>> J;

    for(int i = 0; i < r; ++i)
    {
        std::fill(VF[i], VF[i] + c, -1);
        std::fill(VJ[i], VJ[i] + c, -1);
    }

    for(int i = 0; i < r; ++i)
        std::cin >> board[i];

    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
        {
            if(board[i][j] == 'F')
            {
                F.push({i, j});
                VF[i][j] = 0;
            }
            else if(board[i][j] == 'J')
            {
                J.push({i, j});
                VJ[i][j] = 0;
            }
        }

    while(!F.empty())
    {
        auto cur = F.front(); F.pop();

        for(int dir = 0; dir < 4; ++dir)
        {
            int dirx = cur.first + dx[dir];
            int diry = cur.second + dy[dir];
            if(dirx < 0 || diry < 0 || dirx >= r || diry >= c) continue;
            if(VF[dirx][diry] >= 0 || board[dirx][diry] == '#') continue;
            VF[dirx][diry] = VF[cur.first][cur.second] + 1;
            F.push({dirx, diry});
        }
    }

    while(!J.empty())
    {
        auto cur = J.front(); J.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int dirx = cur.first + dx[dir];
            int diry = cur.second + dy[dir];
            if(dirx < 0 || diry < 0 || dirx >= r || diry >= c)
            {
                std::cout << VJ[cur.first][cur.second] + 1;
                return 0;
            }
            if(VJ[dirx][diry] >= 0 || board[dirx][diry] == '#') continue;
            if(VF[dirx][diry] != -1 && VF[dirx][diry] <= VJ[cur.first][cur.second] + 1) continue;

            VJ[dirx][diry] = VJ[cur.first][cur.second] + 1;
            J.push({dirx, diry});
        }
    }

    std::cout << "IMPOSSIBLE";
}