#include <iostream>
#include <utility>
#include <list>
#include <stack>
#include <queue>
#include <deque>

int main()
{
    std::string input; std::cin >> input;
    std::stack<char> brackets;
    int result = 0;

    for(int i = 0; i < input.size(); ++i)
    {
        if(input[i] == '(')
            brackets.push(i);
        else
        {
            brackets.pop();
            if(input[i - 1] == '(')
                result += brackets.size();
            else
                result++;
        }
    }

    std::cout << result << "\n";
}