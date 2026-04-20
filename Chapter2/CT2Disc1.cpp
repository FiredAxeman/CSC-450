#include <iostream>
#include <cstring>
#include <cstdio>

void vulnerableFunction(const char* userInput) {
    // 1. Buffer Overflow Risk
    char buffer[16];

    // strcpy does not check if userInput is larger than 15 chars + null terminator.
    // If userInput is 50 chars, it will overwrite adjacent memory.
    strcpy(buffer, userInput);

    // 2. Format String Vulnerability
    // If userInput contains "%x" or "%n", it forces printf to read/write memory.
    printf("User entered: ");
    printf(buffer);
    printf("\n");
}

int main() {
    // Imagine this comes from a network packet or user input
    const char* maliciousInput = "This string is way too long for a 16 byte buffer %x %x";
    vulnerableFunction(maliciousInput);
    return 0;
}