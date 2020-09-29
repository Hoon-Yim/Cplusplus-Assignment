#include <iostream>
#include <random>
#include <string>

class GamblingGame
{
private:
    std::string name;
    int random[3]{};

public:
    void SetName(const std::string &pName) { name = pName; }
    [[nodiscard]] std::string GetName() const { return name; }
    void SetRandomNums()
    {
        for(int & i : random)
        {
            std::random_device seed;
            std::mt19937 generate(seed());
            std::uniform_int_distribution<int> range(0,2);
            i = range(generate);
        }
        std::cout << "\t\t\t" << random[0] << "\t" << random[1] << "\t" << random[2];
    }
    bool game()
    {
        if(random[0] == random[1] && random[0] == random[2])
            return true;
        else
            return false;
    }
};

int main()
{
    auto *player = new GamblingGame[2];
    std::string name;
    std::cout << "***** 겜블링 게임을 시작합니다. *****" << std::endl;
    std::cout << "첫번째 선수 이름>>"; std::cin >> name;
    player[0].SetName(name);
    std::cout << "두번째 선수 이름>>"; std::cin >> name;
    player[1].SetName(name);

    std::cin.get();

    for(int i = 0;; i++)
    {
        std::cout << player[i % 2].GetName() << ":<enter> ";
        std::cin.get();
        player[i % 2].SetRandomNums();
        if(player[i % 2].game())
        {
            std::cout << "\t" << player[i % 2].GetName() << "님 승리!!";
            break;
        } else
            std::cout << "\t아쉽군요!" << std::endl;
    }

    delete[] player;
}