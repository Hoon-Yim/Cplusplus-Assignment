#include <iostream>
#include <string>
#include <vector>
#include <stack>

//class student
//{
//private:
//    std::string name;
//    int age;
//    double height;
//    double weight;
//    int grade;
//
//public:
//    void TakeExam();
//    void TakeClass();
//    void DoAssignment();
//    void Study();
//    void GoToSchool();
//};

void sequence(int testcase)
{
    int max = 1;
    std::stack<int> stack;
    std::vector<char> symbol;

    for(int i = 0; i < testcase; ++i)
    {
        int num; std::cin >> num;

        if(!stack.empty() && stack.top() == num)
        {
            stack.pop();
            symbol.push_back('-');
            continue;
        }

        for(int j = max; j <= num; ++j)
        {
            stack.push(j);
            symbol.push_back('+');

            if(j == num)
            {
                stack.pop();
                symbol.push_back('-');
            }
        }

        if(max <= num) max = num + 1;
    }

    if(stack.empty())
    {
    for(auto i : symbol)
        std::cout << i << "\n";
    }
    else
        std::cout << "NO";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);

    int testcase; std::cin >> testcase;
    sequence(testcase);
}