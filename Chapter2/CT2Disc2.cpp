#include <iostream>
#include <string>

// Take userInput as a std::string_view for cheap, read-only string passing
void secureFunction(std::string_view userInput) {
    // 1. Safe Memory Management
    // std::string handles its own memory. No buffer overflow here.
    std::string safeBuffer = std::string(userInput);

    // 2. Safe Output
    // std::cout does not parse format specifiers like %x. It just prints the text.
    std::cout << "User entered: " << safeBuffer << std::endl;
}

int main() {
    std::string safeInput = "This string is way too long for a 16 byte buffer %x %x";
    secureFunction(safeInput);
    return 0;
}