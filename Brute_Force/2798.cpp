/*
 * Last Update : Dec 12 2020
 * Problem : 2798(acmicpc) Black Jack / 블랙잭
 * Link : https://www.acmicpc.net/problem/2798
 */

#include <iostream>

int arr[101];

int Blackjack(int n, int m)
{
    int sum = 0, result = 0;

    for(int i = 0; i < n; ++i)
        std::cin >> arr[i];

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            for(int k = j + 1; k < n; ++k)
            {
                sum = arr[i] + arr[j] + arr[k];
                if(sum <= m && m - sum < m - result) result = sum;
            }
        }
    }

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int n, m; std::cin >> n >> m;
    std::cout << Blackjack(n, m);
}