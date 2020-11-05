#include <iostream>

class Comparable
{
public:
    virtual bool operator > (const Comparable& op2) = 0;
    virtual bool operator < (const Comparable& op2) = 0;
    virtual bool operator == (const Comparable& op2) = 0;
};

class Circle : public Comparable
{
private:
    int m_radius;

public:
    Circle(const int& radius_in = 1)
            : m_radius(radius_in)
    {}

    int GetRadius() const { return m_radius; }

    virtual bool operator < (const Comparable& op2) override
    {
        Circle* temp;
        temp = (Circle*) &op2;

        if(m_radius < temp->GetRadius())
            return true;
        else
            return false;
    }

    virtual bool operator > (const Comparable& op2) override
    {
        Circle* temp;
        temp = (Circle*) &op2;

        if(m_radius > temp->GetRadius())
            return true;
        else
            return false;
    }

    virtual bool operator == (const Comparable& op2) override
    {
        Circle* temp;
        temp = (Circle*) &op2;

        if(m_radius == temp->GetRadius())
            return true;
        else
            return false;
    }
};

template <class T>
T bigger(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    int a = 20, b = 50, c;
    c = bigger(a, b);
    std::cout << "20과 50중 큰 값은 " << c << std::endl;

    Circle waffle(10), pizza(20), y;
    y = bigger(waffle, pizza);
    std::cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.GetRadius() << std::endl;
}