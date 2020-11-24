/*
 * Last Update : Nov 23 2020
 * Problem : 5397(acmicpc) Key Logger / 키로거
 * Link : https://www.acmicpc.net/problem/5397
 */

#include <iostream>
#include <string>
#include <list>

void keylogger(int testcase)
{
    for(int i = 0; i < testcase; ++i)
    {
        std::list<char> keylogger;
        auto cursor = keylogger.begin();

        std::string key; std::cin >> key;
        for(char& j : key) {
            if (j == '<') {
                if (cursor != keylogger.begin())
                    --cursor;
            } else if (j == '>') {
                if (cursor != keylogger.end())
                    ++cursor;
            } else if (j == '-') {
                if (cursor != keylogger.begin()) {
                    --cursor;
                    cursor = keylogger.erase(cursor);
                }
            } else {
                keylogger.insert(cursor, j);
            }
        }

        for(auto& c : keylogger)
            std::cout << c;
        std::cout << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testcase; std::cin >> testcase;
    keylogger(testcase);
    return 0;
}