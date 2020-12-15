/*
 * Last Update : Dec 14 2020
 * Problem : 1074(acmicpc) Z
 * Link : https://www.acmicpc.net/problem/1074
 */

#include <iostream>

int Z(int n, int r, int c)
{
    if(n == 0) return 0;
    int half = 1 << (n - 1);

    if(r < half and c < half) return Z(n - 1, r , c);
    if(r < half and c >= half) return half * half + Z(n - 1, r, c - half);
    if(r >= half and c < half) return 2 * half * half + Z(n - 1, r - half, c);
    return 3 * half * half + Z(n - 1, r - half, c - half);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    std::cout << Z(2, 3, 1);
}