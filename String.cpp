#pragma once

#include "String.h"

String::String()
{
    m_string = nullptr;
    m_length = 0;
}


String::String(const char* string_in)
        : m_length(static_cast<int>(strlen(string_in) + 1))
{
    m_string = new char[m_length];
    strcpy(m_string, string_in);
}
String::String(const String& string)
{
    m_length = string.m_length;
    m_string = new char[m_length];
    strcpy(m_string, string.m_string);
}


String::~String()
{
    if (m_string != nullptr)
    {
        delete[] m_string;
    }
}

String String::operator + (const String& string)
{
    char* temp_char = new char[m_length + string.m_length - 1];
    strcpy(temp_char, m_string);
    strcat(temp_char, string.m_string);

    String temp(temp_char);
    delete[] temp_char;
    return temp;
}

String& String::operator = (const String& string)
{
    if(m_string != nullptr)
        delete[] m_string;

    m_length = string.m_length;
    m_string = new char[m_length];

    strcpy(m_string, string.m_string);

    return *this;
}

bool String::operator == (const String& string)
{
    if(m_length != string.m_length)
        return false;

    for(int i = 0; i < m_length; ++i)
    {
        if(m_string[i] != string.m_string[i])
            return false;
    }

    return true;
}

String& String::operator += (const String& string)
{
    assert(m_string != nullptr);

    m_length += string.m_length - 1;
    char *temp_char = new char[m_length];
    strcpy(temp_char, m_string);
    strcat(temp_char, string.m_string);

    m_string = new char[m_length];
    strcpy(m_string, temp_char);

    delete[] temp_char;

    return *this;
}

std::ostream& operator << (std::ostream& out, const String& string)
{
    if(string.m_string == nullptr)
    {
        std::cout << "Empty String";
        return out;
    }

    out << string.m_string;
    return out;
}

std::istream& operator >> (std::istream& in, String& string)
{
    char temp[100];
    in >> temp;
    string = String(temp);
    return in;
}
