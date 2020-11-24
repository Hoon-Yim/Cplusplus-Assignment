/*
 * Last Update : Nov 23 2020
 * Problem : 10845(acmicpc) Queue / 큐
 * Link : https://www.acmicpc.net/problem/10845
 */

#include <iostream>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::queue<int> stack;

    int testcase; std::cin >> testcase;
    for(int i = 0; i < testcase; ++i)
    {
        std::string option; std::cin >> option;

        if(option == "push")
        {
            int push; std::cin >> push;
            stack.push(push);
        }
        else if(option == "pop")
        {
            if(stack.empty())
                std::cout << -1 << "\n";
            else
            {
                std::cout << stack.front() << "\n";
                stack.pop();
            }
        }
        else if(option == "size")
        {
            std::cout << stack.size() << "\n";
        }
        else if(option == "empty")
        {
            if(stack.empty())
                std::cout << 1 << "\n";
            else
                std::cout << 0 << "\n";
        }
        else if(option == "front")
        {
            if(stack.empty())
                std::cout << -1 << "\n";
            else
                std::cout << stack.front() << "\n";
        }
        else if(option == "back")
        {
            if(stack.empty())
                std::cout << -1 << "\n";
            else
                std::cout << stack.back() << "\n";
        }
    }
    return 0;
}
