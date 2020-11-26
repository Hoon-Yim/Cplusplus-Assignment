/*
 * Last Update : Nov 24 2020
 * Problem : JOSEPHUS(algospot)
 * Link : https://www.algospot.com/judge/problem/read/JOSEPHUS
 */

// Linked List Version

#include <iostream>
#include <list>

void Josephus(int n, int k)
{
    std::list<int> survivor;
    for (int i = 1; i <= n; ++i) survivor.push_back(i);

    auto kill = survivor.begin();

    while(n > 2)
    {
        kill = survivor.erase(kill);
        if(kill == survivor.end()) kill = survivor.begin();

        for(int next = 0; next < k - 1; ++next)
        {
            ++kill;
            if(kill == survivor.end()) kill = survivor.begin();
        }
        --n;
    }

    std::cout << survivor.front() << ' ' << survivor.back() << "\n";
}

int main()
{
    int testcase; std::cin >> testcase;
    for(int i = 0; i < testcase; ++i)
    {
        int n, k; std::cin >> n >> k;
        Josephus(n, k);
    }
}