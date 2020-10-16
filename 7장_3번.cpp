#include <iostream>
#include <string>
#include <utility>

class Book {
private:
    std::string title;
    int price, pages;

public:
    Book(std::string title = "", int price = 0, int pages = 0) : title(std::move(title)), price(price), pages(pages) {}

    void show() const {
        std::cout << title << ' ' << price << "원 " << pages << " 페이지" << std::endl;
    }
    std::string getTitle() {
        return title;
    }

    friend bool operator ! (const Book &ref);
};

bool operator ! (const Book &ref) {
    if(ref.price == 0) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    Book book("벼룩시장", 0, 50); // price is 0
    if(!book) {
        std::cout << "공짜다" << std::endl;
    }
}