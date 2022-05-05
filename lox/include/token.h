#pragma once

#include <iostream>
#include <string>


enum TokenType
{
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,
    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,
    // Literals.
    IDENTIFIER, STRING, NUMBER,
    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    END_OF_FILE
};


class Literal{
public:
    std::string str;
    Literal() { str=""; }
    Literal(std::string str): str(str) {}
};


class Token
{
public:
    TokenType type;
    std::string lexeme;
    Literal literal;
    int line;

    Token(TokenType type, std::string lexeme, Literal literal, int line):
        type(type), lexeme(lexeme), literal(literal), line(line) {} 
};

std::ostream &operator<<(std::ostream &output, const Token &T);
std::ostream &operator<<(std::ostream &output, const Literal &L);