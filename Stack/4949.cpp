/*
 * Last Update : Nov 30 2020
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
        bool check = true; // if brackets are not matched, this will become false
        std::string str;
        std::stack<char> stack;
        getline(std::cin, str); // using getline 'cause we need to get string including space-bar

        // when we put just one period(.) this program will be terminated
        if(str.size() == 1 && str[0] == '.')
            break;

        for(char & i : str)
        {
            if(i == '(' || i == '[')
                stack.push(i);
            else if(i == ')')
            {
                // the reason why 'check' should be false when stack is empty
                // is to prevent ")abed()" this situation
                // because when we use pop function with the empty stack..
                // run-time error will be occurred
                if(stack.empty() || stack.top() != '(')
                {
                    check = false;
                    break;
                }
                stack.pop();
            }
            else if(i == ']')
            {
                if(stack.empty() || stack.top() != '[')
                {
                    check = false;
                    break;
                }
                stack.pop();
            }
        }

        // if there are any remaining brackets in the stack
        // 'check' should be false
        if(!stack.empty()) check = false;
        if(check)
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }
}