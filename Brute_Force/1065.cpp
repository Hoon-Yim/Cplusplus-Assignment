/*
 * Last Update : Dec 12 2020
 * Problem : 1065(acmicpc) Common difference / 한수
 * Link : https://www.acmicpc.net/problem/1065
 */

#include <iostream>

/*
 * base condition1 : if(n < 100) return n;
 * base condition2 : if(n == 100) return han;
 */

int hanNum = 99;
int CD[3];

inline void eCD(int num)
{
    int i = 0;
    while(num)
    {
        CD[i] = num % 10;
        num /= 10; i++;
    }
}

inline void subtraction()
{
    if(CD[0] - CD[1] == CD[1] - CD[2]) hanNum++;
}

int han(int n)
{
    if(n == 1000) hanNum--;
    if(n < 100)
    {
        hanNum = n;
        return hanNum;
    }
    if(n == 100) return hanNum;

    eCD(n);
    subtraction();

    han(n - 1);

    return hanNum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int n; std::cin >> n;
    std::cout << han(n);
}