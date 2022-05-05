#include "token.h"

std::ostream &operator<<(std::ostream &output, const Token &T) {
    output << T.type << ' ' << T.lexeme << ' ' << T.literal;
    return output;
}

std::ostream &operator<<(std::ostream &output, const Literal &L) {
    if (L.str == "") output << "null";
    else output << L.str;
    return output;
}