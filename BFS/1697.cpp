/*
 * Last Update : Dec 08 2020
 * Problem : 1697(acmicpc) Hide-and-seek / 숨바꼭질
 * Link : https://www.acmicpc.net/problem/1697
 */

#include <iostream>
#include <utility>
#include <vector>
#include <queue>

int V[100002];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int n, k; std::cin >> n >> k;

    std::fill(V, V + 100001, -1);

    std::queue<int> Q;
    Q.push(n);
    V[n] = 0;

    while(V[k] == -1)
    {
        int cur = Q.front(); Q.pop();

        for(int dir : {cur - 1, cur + 1, 2 * cur})
        {
            if(dir < 0 || dir > 100000) continue;
            if(V[dir] != -1) continue;
            V[dir] = V[cur] + 1;
            Q.push(dir);
        }
    }

    std::cout << V[k];
}