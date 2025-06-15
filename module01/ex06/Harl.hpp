#pragma once
#include <string>

enum LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    NUM_LOG_LEVELS
};

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    void (Harl::*functions[4])(void);
    std::string levels[4];
    int getLogLevel(const std::string &level) const;

public:
    Harl();
    ~Harl();
    void complain(std::string level);
};
