#pragma once

#include <iostream>
#include <string>

class Error
{
public:
    bool hadError = false;
    void error(int line, std::string message);
private:
    void report(int, std::string, std::string);
};