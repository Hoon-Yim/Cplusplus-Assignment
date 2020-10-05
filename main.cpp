#include <iostream>

class MyClass {
private:
    int size;
    int *element;

public:
    MyClass(int size) : size(size) {
        element = new int[size];
        for(int i = 0; i < size; i++) element[i] = i;
    }
    MyClass(const MyClass &copy) {
        this->size = copy.size;
        this->element = new int[copy.size];
        for(int i = 0; i < size; i++) { element[i] = copy.element[i]; }
    }
    int at(int loc) { return element[loc]; }
    ~MyClass() { if(element) delete[] element; }
};
int main() {
    MyClass a(5);
    MyClass b(a);
    std::cout << b.at(2) << std::endl;
}
