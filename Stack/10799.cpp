/*
 * Last Update : Dec 06 2020
 * Problem : 10799(acmicpc) iron bar / 쇠막대기
 * Link : https://www.acmicpc.net/problem/10799
 */

#include <iostream>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

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