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
    // vector for collecting + and - symbols
    std::vector<char> symbol;

    for(int i = 0; i < testcase; ++i)
    {
        // getting num
        int num; std::cin >> num;

        // if stack is not empty and stack top is equal to num
        // it will just pop the top of the stack and push '-' to vector
        // the reason why stack should not be empty is
        // runtime error could occur
        if(!stack.empty() && stack.top() == num)
        {
            stack.pop();
            symbol.push_back('-');
            continue;
        }

        // this for loop will run until max is less than or equal to
        // because this problem is not allowed to get a num that is less than max
        for(int j = max; j <= num; ++j)
        {
            stack.push(j);
            symbol.push_back('+');

            // every time this for loop runs
            // the last value should be extracted
            if(j == num)
            {
                stack.pop();
                symbol.push_back('-');
            }
        }

        // resetting the max value
        if(max <= num) max = num + 1;
    }

    // when the stack is empty, it means it's available to make a sequence
    // if it isn't, it will print out "NO"
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