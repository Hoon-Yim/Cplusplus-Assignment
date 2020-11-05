//
// Created by SeungHun Yim on 2020-11-02.
//

#ifndef PRACTICE_POINT_H
#define PRACTICE_POINT_H

#include <iostream>

template <class T>
class Point
{
private:
    T m_x, m_y;

public:
    Point()
        : m_x(0), m_y(0)
    {}
    Point(const T& x_in, const T& y_in)
        : m_x(x_in), m_y(y_in)
    {}

    void show() const
    {
        std::cout << '[' << m_x << ", " << m_y << ']' << std::endl;
    }
};

#endif