#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    _hitPoints = 100; // FragTrap's hit points
    _energyPoints = 50; // ScavTrap's energy points
    _attackDamage = 30; // FragTrap's attack damage

    std::cout << "DiamondTrap " << _name << " created." << std::endl;
    std::cout << "Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints
              << ", Attack Damage: " << _attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap " << _name << " copied." << std::endl;
    std::cout << "Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints
              << ", Attack Damage: " << _attackDamage << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
        std::cout << "DiamondTrap " << _name << " assigned." << std::endl;
        std::cout << "Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints
                  << ", Attack Damage: " << _attackDamage << std::endl;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
