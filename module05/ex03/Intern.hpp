#pragma once

#include "AForm.hpp"
#include <string>

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target) const;

private:
    typedef AForm *(*FormCreator)(const std::string &target);

    struct FormEntry
    {
        std::string name;
        FormCreator creator;
    };

    static AForm *createShrubbery(const std::string &target);
    static AForm *createRobotomy(const std::string &target);
    static AForm *createPresidential(const std::string &target);
};
