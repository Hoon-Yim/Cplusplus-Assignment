/*
 * Last Update : Nov 23 2020
 * Problem : 1919(acmicpc) Making Anagram / 애너그램 만들기
 * Link : https://www.acmicpc.net/problem/1919
 */

#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int count = 0;
    std::string str1, str2; std::cin >> str1 >> str2;

    for(int i = 0; i < str1.length(); ++i)
    {
        for(int j = 0; j < str2.length(); ++j)
        {
            if(str1[i] == str2[j])
            {
                str1[i] = '0';
                str2[j] = '0';
            }
        }
    }

    for(auto& i : str1)
    {
        if(i != '0')
            count++;
    }
    for(auto& i : str2)
        if(i != '0')
            count++;

    std::cout << count;
}