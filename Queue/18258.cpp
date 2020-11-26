/*
 * Last Update : Nov 26 2020
 * Problem : 18258(acmicpc) Queue2 / 큐2
 * Link : https://www.acmicpc.net/problem/18258
 */

#include <iostream>
#include <queue>

void queue(int testcase)
{
    std::queue<int> queue;

    for (int i = 0; i < testcase; ++i)
    {
        std::string option; std::cin >> option;

        if(option == "push")
        {
            int add; std::cin >> add;
            queue.push(add);
        }
        else if(option == "pop")
        {
            if(queue.empty())
                std::cout << -1 << "\n";
            else
            {
                std::cout << queue.front() << "\n";
                queue.pop();
            }
        }
        else if(option == "size")
        {
            std::cout << queue.size() << "\n";
        }
        else if(option == "empty")
        {
            (queue.empty()) ? std::cout << 1 << "\n" : std::cout << 0 << "\n";
        }
        else if(option == "front")
        {
            (queue.empty()) ? std::cout << -1 << "\n" : std::cout << queue.front() << "\n";
        }
        else

        {
            (queue.empty()) ? std::cout << -1 << "\n" : std::cout << queue.back() << "\n";
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int testcase; std::cin >> testcase;
    queue(testcase);
}