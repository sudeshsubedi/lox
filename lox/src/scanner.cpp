#include "scanner.h"

std::vector<Token> Scanner::scan_tokens() {
    while (!is_at_end())
    {
        start = current;
        scan_token();
    }
    tokens.push_back(Token(END_OF_FILE, "", Literal(), line));
    return tokens;
}

bool Scanner::is_at_end() {
    return current >= source.length();
}

void Scanner::scan_token() {
    char c = advance();
    switch (c)
    {
        case '(': { add_token(LEFT_PAREN); break; }
        case ')': { add_token(RIGHT_PAREN); break; }
        case '{': { add_token(LEFT_BRACE); break; }
        case '}': { add_token(RIGHT_BRACE); break; }
        case ',': { add_token(COMMA); break; }
        case '.': { add_token(DOT); break; }
        case '-': { add_token(MINUS); break; }
        case '+': { add_token(PLUS); break; }
        case ';': { add_token(SEMICOLON); break; }
        case '*': { add_token(STAR); break; }
        default:
            error_handler->error(line, "Unexpected character");
    }
}

char Scanner::advance() {
    current++;
    return source.at(current-1);
}


void Scanner::add_token(TokenType token_type) {
    add_token(token_type, Literal());
}

void Scanner::add_token(TokenType token_type, Literal literal) {
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token(token_type, text, literal, line));
}