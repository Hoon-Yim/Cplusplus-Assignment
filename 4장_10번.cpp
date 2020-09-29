#include <iostream>
#include <string>
#include <algorithm>

int alphabet[26] = {0,};

class Histogram
{
private:
    std::string str;

public:
    Histogram(const std::string &str) : str(str) {}
    void put(const std::string &pStr);
    void putc(const char &c);
    void print();
};

void Histogram::put(const std::string &pStr) { str += pStr; }
void Histogram::putc(const char &c) { str += c; }
void Histogram::print()
{
    int count = 0;
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); }); // 소문자로 변
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] - 'a' < 0)
            continue;
        else {
            alphabet[str[i] - 'a'] += 1;
            count++;
        }
    }

    std::cout << "총 알파벳 수 " << count << std::endl;

    for(int i = 97; i <= 122; i++)
    {
        std::cout << (char)i << " (" << alphabet[i - 'a'] << ")" << "   :";
        for(int j = 1; j <= alphabet[i - 'a']; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Histogram elvisHisto("Wise men say, only fools rush in But I can't help,");
    elvisHisto.put("falling in love with you");
    elvisHisto.putc('-');
    elvisHisto.put("Elvis Presley");
    elvisHisto.print();
    return 0;
}