//
// Created by SeungHun Yim on 2020-10-29.
//

#pragma once

#include <iostream>
#include "Marine.h"

Marine::Marine()
{
    m_x = m_y = 0;
    m_hp = 50;
    m_damage = 5;
    m_is_dead = false;
}

Marine::Marine(const int &x_in, const int &y_in)
    : m_x(x_in), m_y(y_in)
{
    m_hp = 50;
    m_damage = 5;
    m_is_dead = false;
}

void Marine::Move(const int& x_in, const int& y_in)
{
    m_x = x_in;
    m_y = y_in;
}

int Marine::Attack() const
{
    return m_damage;
}

void Marine::BeAttacked(const int& damage_in)
{
    if(m_is_dead == true)
    {
        std::cout << "This object is not alive" << std::endl;
        return;
    }

    if(damage_in >= m_hp)
    {
        m_is_dead = true;
        std::cout << "Marine is Dead.." << std::endl;
    }

    m_hp -= damage_in;
    std::cout << "Marine HP -" << damage_in << std::endl;
    std::cout << "Marine has been attacked" << std::endl << std::endl;
}

void Marine::ShowStatus() const
{
    std::cout << "*** MARINE ***" << std::endl;
    std::cout << "HP: " << m_hp << std::endl;
    std::cout << "DAMAGE: " << m_damage << std::endl;
    std::cout << "LOCATION: [" << m_x << ", " << m_y << ']' << std::endl << std::endl;
}