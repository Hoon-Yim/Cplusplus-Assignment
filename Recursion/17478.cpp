/*
 * Last Update : Dec 10 2020
 * Problem : 17478(acmicpc) What is recursion function? / 재귀함수가 뭔가요?
 * Link : https://www.acmicpc.net/problem/17478
 */

#include <iostream>

inline void iteration(int k)
{
    for(int i = 0; i < k * 2; ++i)
        std::cout << "__";
}

void recursion(int k, int n)
{
    if(k == n)
    {
        iteration(k);
        std::cout << "\"재귀함수가 뭔가요?\"\n";
        iteration(k);
        std::cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        iteration(k);
        std::cout << "라고 답변하였지.\n";
        return;
    }
    else
    {
        iteration(k);
        std::cout << "\"재귀함수가 뭔가요?\"\n";
        iteration(k);
        std::cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        iteration(k);
        std::cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        iteration(k);
        std::cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
        std::cout << "\n";
    }
    recursion(k + 1, n);
    iteration(k);
    std::cout << "라고 답변하였지.\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int n; std::cin >> n;

    std::cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << std::endl;
    recursion(0, n);
}