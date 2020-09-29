#include <iostream>
#include <string>

class Person
{
private:
    std::string name;
    std::string tel;

public:
    Person() = default;
    [[nodiscard]] std::string getName() const { return name; }
    [[nodiscard]] std::string getTel() const { return tel; }
    void set(const std::string &pName, const std::string &pTel);
};

void Person::set(const std::string &pName, const std::string &pTel)
{
    name = pName;
    tel = pTel;
}

int main()
{
    std::cout << "이름과 전화 번호를 입력해 주세요" << std::endl;
    Person *persons = new Person[3];

    for(int i = 0; i < 3; i++)
    {
        std::string n;
        std::string t;
        std::cout << "사람 " << i + 1 << ">> "; std::cin >> n >> t;
        persons[i].set(n, t);
    }
    std::cout << "모든 사람의 이름은 ";
    for(int i = 0; i < 3; i++)
    {
        std::cout << persons[i].getName() << " ";
    }
    std::cout << std::endl;

    std::string lName;
    std::cout << "전화번호 검색합니다. 이름을 입력하세요>>"; std::cin >> lName;
    for(int i = 0; i < 3; i++)
    {
        if(persons[i].getName() != lName)
            continue;
        else
            std::cout << "전화번호는 " << persons[i].getTel();
    }

    delete[] persons;
    return 0;
}