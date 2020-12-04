#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include <queue>

#define X first
#define Y second

//void top(int testcase)
//{
//    std::vector<int> tops;
//    int max = 1;
//
//    for(int i = 0, index = 0; i < testcase; ++i)
//    {
//        int top; std::cin >> top;
//        tops.push_back(top);
//    }
//
//    for(int i = tops.size() - 1; i >= 0; --i)
//    {
//        int index = 0;
//
//        for(int j = i - 1; j >= 0; --j)
//        {
//            if(tops[i] <= tops[j])
//            {
//                index = j + 1;
//                break;
//            }
//            else
//                index = 0;
//        }
//
//        tops[i] = index;
//    }
//
//    for(auto i : tops)
//        std::cout << i << ' ';
//}

