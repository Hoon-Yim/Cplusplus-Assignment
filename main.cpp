#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <queue>

#define X first
#define Y second

//void top(int testcase)
//{
//    std::vector<int> tops;
//    int max = 1;
//
//    for(int i = 0, index = 0; i < testcase; ++i)
//    {
//        int top; std::cin >> top;
//        tops.push_back(top);
//    }
//
//    for(int i = tops.size() - 1; i >= 0; --i)
//    {
//        int index = 0;
//
//        for(int j = i - 1; j >= 0; --j)
//        {
//            if(tops[i] <= tops[j])
//            {
//                index = j + 1;
//                break;
//            }
//            else
//                index = 0;
//        }
//
//        tops[i] = index;
//    }
//
//    for(auto i : tops)
//        std::cout << i << ' ';
//}

int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int paint_num = 0, max = 0;
    int n, m; std::cin >> n >> m;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            std::cin >> board[i][j];

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(vis[i][j] || board[i][j] == 0) continue;
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
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위가 밖으로 넘어가는 경우를 막아줌
                    if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 빨간칸인 경우
                    vis[nx][ny] = true; // (nx, ny)를 방문했다고 명시
                    Q.push({nx, ny});
                }
            }
            max = std::max(max, area);
        }
    }

    std::cout << paint_num << "\n" << max;
    return 0;
}