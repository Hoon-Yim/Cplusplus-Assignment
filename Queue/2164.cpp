/*
 * Last Update : Nov 26 2020
 * Problem : 2164(acmicpc) Card2 / 카드2
 * Link : https://www.acmicpc.net/problem/2164
 */

#include <iostream>
#include <queue>

void card(int num)
{
    std::queue<int> card;
    int even = 1, temp = 0;

    for(int i = 1; i <= num; ++i)
        card.push(i);

    while(card.size() > 1)
    {
        if(even % 2 != 0)
            card.pop();
        else
        {
            temp = card.front();
            card.pop();
            card.push(temp);
        }
        even++;
    }

    std::cout << card.front();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num;
    std::cin >> num;
    card(num);
}