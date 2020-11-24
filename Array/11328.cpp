/*
 * Last Update : Nov 23 2020
 * Problem : 11328(acmicpc) Strfry
 * Link : https://www.acmicpc.net/problem/11328
 */

#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int TC;
    std::cin >> TC;

    for (int i = 0; i < TC; ++i) {
        int firAlpha[26] = {0,};
        int secAlpha[26] = {0,};

        bool check = true;
        std::string str1, str2;
        std::cin >> str1 >> str2;

        if (str1.length() != str2.length()) {
            std::cout << "Impossible" << std::endl;
            continue;
        }

        for (int j = 0; j < str2.length(); ++j) {
            firAlpha[str1[j] - 'a']++;
            secAlpha[str2[j] - 'a']++;
        }

        for (int j = 0; j < 26; ++j) {
            if (firAlpha[j] != secAlpha[j]) {
                std::cout << "Impossible" << std::endl;
                check = false;
                break;
            }
        }

        if (check)
            std::cout << "Possible" << std::endl;
    }
}