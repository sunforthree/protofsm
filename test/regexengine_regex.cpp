#include "../../src/src_regex.h"

#include <stdio.h>
#include <iostream>
#include <cassert>

#define DEBUG

using namespace sunfor3;

int main() {
    re2::StringPiece pattern = "(\\w+):(\\d+)";
    RegexEngine re(pattern);
    std::string s;
    re2::StringPiece text = "ruby:1234";
    if (re2::RE2::FullMatch(text, *re.re2(), &s)) {
        std::cout << "normal function match!\n";
        std::cout << "s is: " << s << '\n';
    }
    if (RegexEngine::Match(text, re, RegexEngine::FullMatch, &s)) {
        std::cout << "Match!\n";
        std::cout << "s is: " << s << '\n';
    }
    return 0;
}