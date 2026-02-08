#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));

    std::cout << "===== ShrubberyCreationForm =====" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 130);
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
        std::cout << "(Check home_shrubbery file)" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== RobotomyRequestForm =====" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 1);
        RobotomyRequestForm robot("Bender");
        std::cout << robot << std::endl;
        alice.signForm(robot);
        alice.executeForm(robot);
        alice.executeForm(robot);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== PresidentialPardonForm =====" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== Execute unsigned form =====" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm pardon("Ford");
        boss.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== Grade too low to execute =====" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150);
        ShrubberyCreationForm shrub("garden");
        Bureaucrat boss("Boss", 1);
        boss.signForm(shrub);
        intern.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "===== Grade too low to sign =====" << std::endl;
    try
    {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Zaphod");
        intern.signForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
