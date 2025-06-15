#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
    functions[DEBUG] = &Harl::debug;
    functions[INFO] = &Harl::info;
    functions[WARNING] = &Harl::warning;
    functions[ERROR] = &Harl::error;

    levels[DEBUG] = "DEBUG";
    levels[INFO] = "INFO";
    levels[WARNING] = "WARNING";
    levels[ERROR] = "ERROR";
}

Harl::~Harl()
{
    // Destructor does nothing for now
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\n"
              << "I think I deserve to have some extra bacon for free." << std::endl
              << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::getLogLevel(const std::string &level) const
{
    for (int i = 0; i < NUM_LOG_LEVELS; ++i)
    {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

void Harl::complain(std::string level)
{
    int logLevel = getLogLevel(level);
    
    switch (logLevel)
    {
        case DEBUG:
            debug();
            std::cout << std::endl;
            /* fall through */
        case INFO:
            info();
            std::cout << std::endl;
            /* fall through */
        case WARNING:
            warning();
            std::cout << std::endl;
            /* fall through */
        case ERROR:
            error();
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
