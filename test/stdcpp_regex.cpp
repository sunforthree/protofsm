#include <iostream>
#include <regex>

int main() {
    auto const regex = std::regex("(my|your|their) regex");

    auto const myText = std::string("A piece of text that contains my regex.");

    bool const myTextContainRegex = std::regex_search(myText, regex);

    auto const yourText = std::string("A piece of text that contains your regex.");
    bool const yourTextContainsRegex = std::regex_search(yourText, regex);

    auto const theirText = std::string("A piece of text that contains their regex.");
    bool const theirTextContainsRegex = std::regex_search(theirText, regex);

    std::cout << std::boolalpha
              << myTextContainRegex << '\n'
              << yourTextContainsRegex << '\n'
              << theirTextContainsRegex << '\n';

    const char * test_ptr = NULL;

    if (!test_ptr) std::cout << "ptr is null!\n";
    else std::cout << test_ptr << '\n';

    return 0;
}