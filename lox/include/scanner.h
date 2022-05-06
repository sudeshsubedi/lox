#pragma once

#include <string>
#include <vector>
#include "token.h"
#include "errors.h"


class Scanner
{
public:
    Scanner(std::string src, Error* error_handler):source(src), error_handler(error_handler) {}
    std::vector<Token> scan_tokens();
private:
    std::string source;
    Error* error_handler;
    std::vector<Token> tokens;
    int start = 0, current = 0, line = 1;
    bool is_at_end();
    void scan_token();
    char advance();
    void add_token(TokenType);
    void add_token(TokenType, Literal);
    bool match(char);
    char peek();
    void string();
    bool is_digit(char);
    void number();
    char peek_next();
    bool is_alpha(char);
    bool is_alpha_numeric(char);
    void identifier();
};