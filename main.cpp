#include <iostream>

class BaseArray {
private:
    int capacity;
    int *mem;

protected:
    BaseArray(int capacity = 100) : capacity(capacity) {
        mem = new int[capacity];
    }
    ~BaseArray() {
        delete[] mem;
    }

    void put(int index, int val) {
        mem[index] = val;
    }
    int get(int index) {
        return mem[index];
    }
    int getCapacity() {
        return capacity;
    }
};

class MyStack : public BaseArray {
private:
    int len;

public:
    MyStack(int capacity = 100) : BaseArray(capacity) {
        len = 0;
    }

    void push(int a) {
        put(len, a);
        len++;
    }
    int pop() {
        len--;
        return get(len);
    }

    int capacity() {
        int cap = getCapacity();
        return cap;
    }
    int length() {
        return len;
    }
};

int main() {
    MyStack mStack(100);
    int n;
    std::cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
    for(int i = 0; i < 5; i++) {
        std::cin >> n;
        mStack.push(n); // 스택에 푸시
    }

    std::cout << "스택용량:" << mStack.capacity() << ", 스택크기:" << mStack.length() << std::endl;
    std::cout << "스택의 모든 원소를 팝하여 출력한다>> ";
    while(mStack.length() != 0) {
        std::cout << mStack.pop() << ' '; // 스택에서 팝
    }
    std::cout << std::endl << "스택의 현재 크기 : " << mStack.length() << std::endl;
}
