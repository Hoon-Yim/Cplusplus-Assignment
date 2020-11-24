#include <iostream>
#include <algorithm>
#include <random>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int input)
{
    dat[--head] = input;
}
void push_back(int input)
{
    dat[tail++] = input;
}
void pop_front()
{
    head++;
}
void pop_back()
{
    tail--;
}

int front()
{
    return dat[head];
}
int back()
{
    return dat[tail - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::deque<int> stack;

    int testcase; std::cin >> testcase;
    for(int i = 0; i < testcase; ++i)
    {
        std::string option; std::cin >> option;

        if(option == "push_front")
        {
            int push; std::cin >> push;
            stack.push_front(push);
        }
        else if(option == "push_back")
        {
            int push; std::cin >> push;
            stack.push_back(push);
        }
        else if(option == "pop_front")
        {
            if(stack.empty())
                std::cout << -1 << "\n";
            else
            {
                std::cout << stack.front() << "\n";
                stack.pop_front();
            }
        }
        else if(option == "pop_back")
        {
            if(stack.empty())
                std::cout << -1 << "\n";
            else
            {
                std::cout << stack.back() << "\n";
                stack.pop_back();
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
