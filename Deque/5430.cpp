/*
 * Last Update : Nov 28 2020
 * Problem : 5430(acmicpc) AC
 * Link : https://www.acmicpc.net/problem/5430
 */

/*
 * 나를 많이 성장시켜준 문제
 * 문제를 푸는데에 5시간 정도가 걸렸다
 * 문자열에서 숫자를 뽑아내는 함수를 직접 작성하고
 * 덱을 Reverse 해야되는데 boolean 타입을 이용해서
 * 실제로 뒤집지않고 뒤집은 효과를 낼 수 있다는 기법을 알아냄
 * reverse 함수를 사용하면 시간초과가 걸림
 * 다른 문제에서도 종종 사용될 것으료 예상됨
 */

#include <iostream>
#include <string>
#include <deque>

std::deque<int> deque;

inline void extract(std::string str)
{
    int temp = 0;
    for(int i = 1; i < str.length(); ++i)
    {
        if(str[i] >= '0' && str[i] <= '9')
            temp = temp * 10 + (static_cast<int>(str[i]) - 48);
        else if((str[i] == ',' || i + 1 == str.length()) && temp != 0)
        {
            deque.push_back(temp);
            temp = 0;
        }
    }
}

void AC(int testcase)
{
    for(int i = 0; i < testcase; ++i)
    {
        deque.clear();
        std::string option; std::cin >> option;
        int size; std::cin >> size;
        std::string nums; std::cin >> nums; extract(nums);
        bool reverse = false, error = false;

        for(char j : option)
        {
            if(j == 'R')
                reverse = !reverse;
            else if(j == 'D')
            {
                if(deque.empty())
                {
                    error = true;
                    break;
                }
                if(reverse) deque.pop_back();
                else deque.pop_front();
            }
        }

        if(error)
            std::cout << "error\n";
        else if(deque.empty())
            std::cout << "[]\n";
        else if(reverse)
        {
            std::cout << "[";
            while(deque.size() > 1)
            {
                std::cout << deque.back() << ',';
                deque.pop_back();
            }
            std::cout << deque.back() << "]\n";
        }
        else
        {
            std::cout << "[";
            while(deque.size() > 1)
            {
                std::cout << deque.front() << ',';
                deque.pop_front();
            }
            std::cout << deque.front() << "]\n";
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int testcase; std::cin >> testcase;
    AC(testcase);
}