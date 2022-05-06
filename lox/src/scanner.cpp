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
        case '!':
            add_token(match('=')? BANG_EQUAL : BANG);
            break;
        case '=':
            add_token(match('=')? EQUAL_EQUAL : EQUAL);
            break;
        case '<':
            add_token(match('=')? LESS_EQUAL : LESS);
            break;
        case '>':
            add_token(match('=')? GREATER_EQUAL : GREATER);
            break;
        case '/':
            if(match('/')) {
                while(peek() != '\n' && !is_at_end()) advance();
            } else {
                add_token(SLASH);
            }
            break;
        case ' ':
        case '\t':
        case '\r':
            break;
        case '\n':
            line++;
            break;
        case '"': { string(); break; }
        default:
        if(is_digit(c)) {
            number();
        } else if(is_alpha(c)) {
            identifier();
        } else {
            error_handler->error(line, "Unexpected character");
        }
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

bool Scanner::match(char expected) {
    if(is_at_end()) return false;
    if(source.at(current) != expected) return false;
    current++;
    return true;
}

char Scanner::peek() {
    if(is_at_end()) return '\0';
    return source.at(current);
}

void Scanner::string() {
    while(peek() != '"' && !is_at_end()){
        if(peek() == '\n') line++;
        advance();
    }

    if(is_at_end()) {
        error_handler->error(line, "Unterminated string");
    }

    advance();

    std::string text = source.substr(start+1, current - start - 2);
    add_token(STRING, Literal(text));
}

bool Scanner::is_digit(char c) {
    return c >= '0' && c <= '9';
}

void Scanner::number() {
    while(is_digit(peek())) advance();

    if(peek() == '.' && is_digit(peek_next())) {
        advance();

        while(is_digit(peek())) advance();
    }
    double num = std::stod(source.substr(start, current - start));
    add_token(NUMBER, Literal(num)); // TODO modify literal so take and store number literal as double
}

char Scanner::peek_next() {
    if(current + 1 >= source.length()) return '\0';
    return source.at(current+1);
}

bool Scanner::is_alpha(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           c == '_';
}

bool Scanner::is_alpha_numeric(char c) {
    return is_alpha(c) || is_digit(c);
}

void Scanner::identifier() {
    while(is_alpha_numeric(peek())) advance();

    add_token(IDENTIFIER);
}

