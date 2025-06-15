#pragma once
#include <string>

class Weapon;

class HumanB
{
private:
    std::string name;
    Weapon *weapon;

public:
    HumanB(const std::string &name);
    ~HumanB();

    void setWeapon(Weapon &weapon);
    void attack() const;
};
