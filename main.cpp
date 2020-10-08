#include <iostream>

int main() {
    int *ptr = nullptr;

    std::cout << ptr << ' ' << (long long)ptr << std::endl;
    ptr++;
    std::cout << ptr << ' ' << (long long)ptr << std::endl;
    return 0;
}