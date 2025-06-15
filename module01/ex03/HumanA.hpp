#pragma once
#include <string>

class Weapon;

class HumanA
{
private:
    std::string name;
    Weapon &weapon;

public:
    HumanA(const std::string &name, Weapon &weapon);
    ~HumanA();

    void attack() const;
};
