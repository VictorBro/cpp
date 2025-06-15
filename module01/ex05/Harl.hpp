#pragma once
#include <string>

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void (Harl::*functions[4])(void);
    std::string levels[4];

public:
    Harl();
    ~Harl();
    void complain(std::string level);
};
