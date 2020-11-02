#ifndef PRACTICE_STRING_H
#define PRACTICE_STRING_H

#include <iostream>

class String
{
private:
private:
    char *m_string;
    int m_length;

public:
    String();
    String(const char* string_in);
    String(const String& string);

    String operator + (const String& string);
    String& operator = (const String& string);
    bool operator == (const String& string);
    String& operator += (const String& string);
    friend std::ostream& operator << (std::ostream& out, const String& string);
    friend std::istream& operator >> (std::istream& in, String& string);

    ~String();
};

#endif //PRACTICE_STRING_H
