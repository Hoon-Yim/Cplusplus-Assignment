#include <iostream>

class Circle
{
private:
    int radius;

public:
    explicit Circle(int r) : radius(r) {}
    [[nodiscard]] int GetRadius() const { return radius; }
    void SetRadius(int r) { radius = r; }
    void show() const { std::cout << "반지름이 " << radius << "인 원" << std::endl; }
};

void IncreaseBy(Circle &a, Circle &b)
{
    int r = a.GetRadius() + b.GetRadius();
    a.SetRadius(r);
}

int main()
{
    Circle x(10), y(5);
    IncreaseBy(x, y);
    x.show();
    return 0;
}
