/*
 * Last Update : Nov 23 2020
 * Problem : 1475(acmicpc) Room Number / 방 번호
 * Link : https://www.acmicpc.net/problem/1475
 */

#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int digit[10]{0,}, room;
    std::cin >> room;

    if(room == 0)
    {
        std::cout << 1 << std::endl;
        return 0;
    }

    while(room)
    {
        int temp = room % 10;
        if(temp == 6)
            digit[temp + 3]++;
        else
            digit[temp]++;

        room /= 10;
    }

    (digit[9] % 2 == 0) ? digit[9] /= 2 : digit[9] = digit[9] / 2 + 1;
    std::sort(digit, digit + 10, std::greater<int>());

    std::cout << digit[0] << std::endl;
}