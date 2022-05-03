#pragma once

#include <string>
#include <vector>
#include "token.h"


class Scanner
{
public:
    Scanner(std::string src):source(src) {}
    std::vector<Token> scan_tokens();
private:
    std::string source;
};