//
// Created by SeungHun Yim on 2020-10-29.
//

#ifndef PRACTICE_MARINE_H
#define PRACTICE_MARINE_H

class Marine
{
private:
    int m_x, m_y;
    int m_hp;
    int m_damage;
    bool m_is_dead;

public:
    Marine();
    Marine(const int& x_in, const int& y_in);

    void Move(const int& x_in, const int& y_in);
    int Attack() const;
    void BeAttacked(const int& damage_in);
    void ShowStatus() const;
};

#endif //PRACTICE_MARINE_H
