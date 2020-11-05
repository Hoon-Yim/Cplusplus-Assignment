#include <iostream>
#include <string>
#include <vector>
#include <utility>


class Book
{
private:
    int m_year;
    std::string m_title;
    std::string m_author;

public:
    Book(const int& year_in, std::string title_in, std::string author_in)
            : m_year(year_in), m_title(std::move(title_in)), m_author(std::move(author_in))
    {}

    int GetYear() const { return m_year; }
    std::string GetTitle() const { return m_title; }
    std::string GetAuthor() const { return m_author; }

    friend std::ostream& operator << (std::ostream& out, const Book& book);
};

std::ostream& operator << (std::ostream& out, const Book& book)
{
    out << book.m_year << "년도, " << book.m_title << ", " << book.m_author;
    return out;
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector <Book> v;

    while (true) {
        int year = 0;
        std::string title, author;

        std::cout << "년도>>";
        std::cin >> year;
        std::cin.ignore();
        if (year == -1)
            break;

        std::cout << "책이름>>";
        std::getline(std::cin, title);
        std::cout << "저자>>";
        std::getline(std::cin, author);

        v.push_back(Book(year, title, author));
    }

    std::cout << "총 입고된 책은 " << v.size() << "권입니다." << std::endl;

    std::string author;
    int year = 0;

    std::cout << "검색하고자 하는 저자 이름을 입력하세요>>";
    std::getline(std::cin, author);
    for (auto &i : v) {
        if (i.GetAuthor() == author) {
            std::cout << i << std::endl;
        }
    }

    std::cout << "검색하고자 하는 년도를 입력하세요>>";
    std::cin >> year;
    for (auto &i : v) {
        if (i.GetYear() == year) {
            std::cout << i << std::endl;
        }
    }
}