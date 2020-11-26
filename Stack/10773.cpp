/*
 * Last Update : Nov 25 2020
 * Problem : 10773(acmicpc) Zero / 제로
 * Link : https://www.acmicpc.net/problem/10773
 */

#include <iostream>

int stack[100000];
int tail = 0;

void push(int n)
{
    stack[tail++] = n;
}
void pop()
{
    tail--;
}
int back()
{
    return stack[tail - 1];
}
int size()
{
    return tail - 1;
}


void zero(int testcase)
{
    int sum = 0;

    for(int i = 0; i < testcase; ++i)
    {
        int temp; std::cin >> temp;
        if(temp == 0)
        {
            if(tail != 0)
            {
                pop();
                sum -= stack[tail];
            }
        }
        else
        {
            sum += temp;
            push(temp);
        }
    }

    std::cout << sum;
}

int main()
{
    int testcase; std::cin >> testcase;

    zero(testcase);
}