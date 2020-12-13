/*
 * Last Update : Dec 13 2020
 * Problem : 2231(acmicpc) 분해합
 * Link : https://www.acmicpc.net/problem/2231
 */

#include <iostream>

int arr[7], i;

inline void E(int num)
{
    while(num)
    {
        arr[i] = num % 10;
        num /= 10; i++;
    }
}

inline int addition()
{
    int sum = 0;
    for(int j = 0; j <= i; ++j)
        sum += arr[j];

    i = 0;
    return sum;
}

int ADD(int num)
{
    for(int j = 1; j <= num; ++j)
    {
        std::fill(arr, arr + 6, 0);
        E(j);
        if(j + addition() == num)
            return j;
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int num; std::cin >> num;
    std::cout << ADD(num);
}