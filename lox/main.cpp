#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "scanner.h"
#include "errors.h"

void runFile(std::string, Error*);
void runPrompt(Error*);
void run(std::string);



int main(int argc, char** argv) {
    Error errorhandler;
    if(argc > 2) {
        std::cout << "Usage: lox [file]" << std::endl;
        return 64;
    }else if (argc == 2) {
        runFile(argv[1], &errorhandler);
    }else {
        runPrompt(&errorhandler);
    }
}

void runFile(std::string path, Error* error_handler) {
    std::ifstream f(path);
    std::string s;
    if(f) {
        std::ostringstream ss;
        ss << f.rdbuf();
        s = ss.str();
        //std::cout << s << std::endl;
        run(s);
        if(error_handler->hadError) system("exit 64");
    }
}

void runPrompt(Error* error_handler) {
    while(true) {
        std::cout << ">";
        std::string s;
        std::getline(std::cin, s);
        //if(s==) break;
        run(s);
        error_handler->hadError = true;
    }
}

void run(std::string source) {
    Scanner scanner(source);
    std::vector<Token> tokens = scanner.scan_tokens();

    // for(auto& token: tokens) {
    //     std::cout << token << '\n';
    // }
}