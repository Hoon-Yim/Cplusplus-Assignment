/*
 * Last Update : Nov 23 2020
 * Problem : 4949(acmicpc) Balanced World / 균형잡힌 세
 * Link : https://www.acmicpc.net/problem/4949
 */

#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    while(true)
    {
        bool check = false;
        std::string str;
        std::stack<char> stack;
        getline(std::cin, str);

        if(str.size() == 1 && str[0] == '.')
            break;

        for(char & i : str)
        {
            if(i == '(' || i == '[')
                stack.push(i);
            else if(i == ')')
            {
                if(stack.empty() || stack.top() != '(')
                {
                    check = true;
                    break;
                }
                stack.pop();
            }
            else if(i == ']')
            {
                if(stack.empty() || stack.top() != '[')
                {
                    check = true;
                    break;
                }
                stack.pop();
            }
        }

        if(!stack.empty()) check = true;
        if(!check)
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }
}