/*
 * Last Update : Nov 23 2020
 * Problem : 13300(acmicpc) Room Assignment / 방 배정
 * Link : https://www.acmicpc.net/problem/13300
 */

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int men[6] = {0,};
    int women[6] = {0,};
    int sum = 0;

    int stu_num, max_peo;
    std::cin >> stu_num >> max_peo;

    for(int i = 0; i < stu_num; ++i)
    {
        int sex, year;
        std::cin >> sex >> year;

        if(sex < 0 || sex > 1 || year < 1 || year > 6)
            return 0;

        if(sex == 0)
        {
            women[year - 1]++;
            if(women[year - 1] == max_peo)
            {
                sum++;
                women[year - 1] -= max_peo;
            }
        }
        else
        {
            men[year - 1]++;
            if(men[year - 1] == max_peo)
            {
                sum++;
                men[year - 1] -= max_peo;
            }
        }
    }

    for(int i = 0; i < 6; ++i)
    {
        if(women[i] > 0)
            sum++;
        if(men[i] > 0)
            sum++;
    }

    std::cout << sum;
}