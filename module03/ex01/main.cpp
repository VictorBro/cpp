#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    {
        ClapTrap claptrap("Clappy");
        ClapTrap copy = claptrap;    // Copy constructor
        copy = ClapTrap("Assigned"); // Assignment operator
        claptrap.attack("target1");
        claptrap.takeDamage(5);
        claptrap.beRepaired(3);
        claptrap.takeDamage(10); // This should destroy the ClapTrap
        claptrap.beRepaired(5);  // This should not work since ClapTrap is destroyed
        copy.attack("target2");
    }
    std::cout << "------------------------" << std::endl;
    ScavTrap scavtrap("Scavvy");
    scavtrap.attack("target3");
    scavtrap.guardGate();

    return 0;
}