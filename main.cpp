#include <iostream>

std::istream& pos(std::istream& ins)
{
    std::cout << "위치는? ";
    return ins;
}

int main()
{
    int x, y;
    std::cin >> pos >> x;
    std::cin >> pos >> y;

    std::cout << x << ", " << y;
}