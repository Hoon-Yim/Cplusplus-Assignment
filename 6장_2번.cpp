#include <iostream>
#include <utility>

class Person
{
private:
    int id;
    double weight;
    std::string name;

public:
    Person() { id = 1; weight = 20.5; name = "Grace"; };
    Person(int id, std::string name) : id(id), name(std::move(name)) { weight = 20.5; }
    Person(int id, std::string name, double weight) : id(id), name(std::move(name)), weight(weight) {}
    void show() { std::cout << id << ' ' << weight << ' ' << name << std::endl; }
};

int main()
{
    Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
    grace.show();
    ashley.show();
    helen.show();
}