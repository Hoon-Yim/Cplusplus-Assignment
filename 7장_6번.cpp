#include <iostream>

class Matrix {
private:
    int mat[4];

public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0) {
        mat[0] = a;
        mat[1] = b;
        mat[2] = c;
        mat[3] = d;
    }

    void show() const {
        std::cout << "Matrix = { ";
        for(int i : mat) {
            std::cout << i << ' ';
        }
        std::cout << "}" << std::endl;
    }

//    void operator << (const int arr[]) {
//        for(int i = 0; i < 4; i++) {
//            mat[i] = arr[i];
//        }
//    }
//
//    void operator >> (int arr[]) const {
//        for(int i = 0; i < 4; i++) {
//            arr[i] = mat[i];
//        }
//    }

    friend void operator << (Matrix &a, const int arr[]);
    friend void operator >> (Matrix a, int arr[]);
};

void operator << (Matrix &a, const int arr[]) {
    for(int i = 0; i < 4; i++) {
        a.mat[i] = arr[i];
    }
}
void operator >> (Matrix a, int arr[]) {
    for(int i = 0; i < 4; i++) {
        arr[i] = a.mat[i];
    }
}

int main() {
    Matrix a(4, 3, 2, 1), b;
    int x[4], y[4] = { 1, 2, 3, 4 }; // 2치원 행렬의 4 개의 원소 값

    a >> x; // a의 각 원소를 배열 x에 복사, x[]는 { 4, 3, 2, 1 }
    b << y; // 배열 y의 원소 값을 b의 각 원소에 설정

    for(int i = 0; i < 4; i++) {
        std::cout << x[i] << ' ';
    }
    std::cout << std::endl;
    b.show();
}