#include "errors.h"

void Error::error(int line, std::string message) {
    report(line, "", message);
}

void Error::report(int line, std::string where, std::string message) {
    std::cout << "[line " << line << "] Error" << where << ": " << message <<std::endl;
    hadError = true;
}