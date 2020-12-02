/*
 * Last Update : Dec 02 2020
 * Problem : 1874(acmicpc) Stack sequence / 스택 수열
 * Link : https://www.acmicpc.net/problem/1874
 */

#include <iostream>
#include <stack>
#include <vector>

void sequence(int testcase)
{
    int max = 1;
    std::stack<int> stack;
    std::vector<char> symbol;

    for(int i = 0; i < testcase; ++i)
    {
        int num; std::cin >> num;

        if(!stack.empty() && stack.top() == num)
        {
            stack.pop();
            symbol.push_back('-');
            continue;
        }

        for(int j = max; j <= num; ++j)
        {
            stack.push(j);
            symbol.push_back('+');

            if(j == num)
            {
                stack.pop();
                symbol.push_back('-');
            }
        }

        if(max <= num) max = num + 1;
    }

    if(stack.empty())
    {
        for(auto i : symbol)
            std::cout << i << "\n";
    }
    else
        std::cout << "NO";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int testcase; std::cin >> testcase;
    sequence(testcase);
}