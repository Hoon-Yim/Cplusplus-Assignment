//
// Created by SeungHun Yim on 2020-11-02.
//

#ifndef PRACTICE_ARRAYTEMPLATE_H
#define PRACTICE_ARRAYTEMPLATE_H

#include <iostream>

template <class T>
class Array
{
private:
    T* m_arr;
    int m_arrlen;

public:
    Array()
        : m_arr(nullptr), m_arrlen(0)
    {}
    Array(const int& len_in)
        : m_arrlen(len_in)
    {
        m_arr = new T[len_in];
    }

    T& operator [] (const int& index);
    T operator [] (const int& index) const;
    int GetArrLen() const;

    ~Array();
};

template <class T>
T& Array<T>::operator [] (const int& index)
{
    if(index < 0 || index >= m_arrlen)
    {
        std::cout << "Invalid Access" << std::endl;
        exit(1);
    }

    return m_arr[index];
}

template <class T>
T Array<T>::operator [] (const int& index) const
{
    if(index < 0 || index >= m_arrlen)
    {
        std::cout << "Invalid Access" << std::endl;
        exit(1);
    }

    return m_arr[index];
}

template <class T>
int Array<T>::GetArrLen() const
{
    return m_arrlen;
}

template <class T>
Array<T>::~Array()
{
    if(m_arr != nullptr)
        delete[] m_arr;
}

#endif //PRACTICE_ARRAYTEMPLATE_H