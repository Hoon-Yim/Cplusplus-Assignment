/*
 * Last Update : Nov 23 2020
 * Problem : 1406(acmicpc) Editor / 에디터
 * Link : https://www.acmicpc.net/problem/1406
 */

#include <iostream>
#include <string>
#include <list>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str; std::cin >> str;
    std::list<char> list_char;

    for(auto& i : str)
        list_char.push_back(i);

    int TC; std::cin >> TC;

    auto cursor = list_char.end();

    for(int i = 0; i < TC; ++i)
    {
        char option; std::cin >> option;

        if(option == 'L')
        {
            if(cursor != list_char.begin())
                cursor--;
        }
        else if(option == 'D')
        {
            if(cursor != list_char.end())
                cursor++;
        }
        else if(option == 'P')
        {
            char add; std::cin >> add;
            list_char.insert(cursor, add);
        }
        else
        {
            if(cursor != list_char.begin())
            {
                cursor--;
                cursor = list_char.erase(cursor);
            }
        }
    }

    for(auto& i : list_char)
        std::cout << i;
}