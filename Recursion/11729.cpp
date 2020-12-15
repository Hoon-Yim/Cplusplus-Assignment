/*
 * Last Update : Dec 14 2020
 * Problem : 11729(acmicpc) The order of movement of Hanoi top / 하노이 탑 이동 순서
 * Link : https://www.acmicpc.net/problem/11729
 */

#include <iostream>

void hanoi(int from, int to, int n)
{
    if(n == 1)
    {
        std::cout << from << ' ' << to << "\n";
        return;
    }
    hanoi(from, 6 - from - to, n - 1);
    std::cout << from << ' ' << to << "\n";
    hanoi(6 - from - to, to, n - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int n; std::cin >> n;
    std::cout << (1 << n) - 1 << "\n";
    hanoi(1, 3, n);
}