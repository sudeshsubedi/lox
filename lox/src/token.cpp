#include "token.h"

std::ostream &operator<<(std::ostream &output, const Token &T) {
    output << T.type << ' ' << T.lexeme << ' ' << T.literal;
    return output;
}

std::ostream &operator<<(std::ostream &output, const Literal &L) {
    if (L.is_null) {
        output << "null";
    } else if (L.is_str) {
        output << L.str;
    } else if(L.is_num) {
        output << L.num;
    }
    return output;
}