/*
 * Last Update : Nov 24 2020
 * Problem : JOSEPHUS(algospot)
 * Link : https://www.algospot.com/judge/problem/read/JOSEPHUS
 */

// Queue Version

#include <iostream>
#include <queue>

void Josephus(int n, int k)
{
    std::queue<int> survivors;
    for(int i = 1; i <= n; ++i) survivors.push(i);

    while(n > 2)
    {
        survivors.pop();

        for(int next = 0; next < k - 1; ++next)
        {
            int temp = survivors.front();
            survivors.pop();
            survivors.push(temp);
        }
        --n;
    }
    std::cout << survivors.front() << ' ' << survivors.back() << "\n";
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