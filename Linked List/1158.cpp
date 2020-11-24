/*
 * Last Update : Nov 23 2020
 * Problem : 1158(acmicpc) Josephus / 요세푸스
 * Link : https://www.acmicpc.net/problem/1158
 */

#include <iostream>
#include <list>

void Josephus(int n, int k)
{
    std::list<int> fcorps;
    for(int i = 1; i <= n; ++i) fcorps.push_back(i);

    auto kill = fcorps.begin();
    for(int i = 0; i < k - 1; ++i)
        ++kill;

    std::cout << '<';
    while(n > 0)
    {
        if(n == 1)
            std::cout << *kill << '>';
        else
            std::cout << *kill << ", ";
        kill = fcorps.erase(kill);
        if(kill == fcorps.end()) kill = fcorps.begin();

        for(int i = 0; i < k - 1; ++i)
        {
            ++kill;
            if(kill == fcorps.end()) kill = fcorps.begin();
        }

        --n;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k; std::cin >> n >> k;
    Josephus(n, k);

    return 0;
}
