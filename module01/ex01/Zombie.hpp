#pragma once
#include <string>

class Zombie
{
private:
    std::string name;

public:
    Zombie();
    Zombie(const std::string &name);
    ~Zombie();

    void setName(const std::string &name);
    void announce();
};

Zombie *zombieHorde(int N, std::string name);
