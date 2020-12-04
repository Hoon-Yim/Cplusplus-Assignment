#include <iostream>
#include <utility>
#include <vector>
#include <stack>
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

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}};
bool vis[502][502];

int main()
{
    int n = 7, m = 10;
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    std::queue<std::pair<int, int>> Q; // 탐색이 언제 끝나는지 체크하는 용도의 queue

    vis[0][0] = true; // 이미 방문했다고 표시
    Q.push({0, 0});

    while(!Q.empty())
    {
        std::pair<int, int> cur = Q.front(); Q.pop();
        std::cout << "(" << cur.first << ", " << cur.second << ") -> ";

        for(int direction = 0; direction < 4; ++direction)
        {
            int nx = cur.first + dx[direction];
            int ny = cur.second + dy[direction];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = true; // (nx, ny)를 방문했다고 명시
            Q.push({nx, ny});
        }
    }
}
