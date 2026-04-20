#include <iostream>
#include <string>

int main() {
    // Variables to hold the user input and the final concatenated string
    std::string string1;
    std::string string2;
    std::string combinedString;

    std::cout << "--- String Concatenation Program ---\n";

    // Loop exactly 3 times
    for (int i = 1; i <= 3; ++i) {
        std::cout << "\nAttempt " << i << " of 3\n";
        std::cout << "----------------\n";

        // Get the first string
        std::cout << "Enter the first string: ";
        std::getline(std::cin, string1);

        // Get the second string
        std::cout << "Enter the second string: ";
        std::getline(std::cin, string2);

        // Concatenate the strings
        combinedString = string1 + string2;

        // Print the resulting output
        std::cout << "Concatenated Output: " << combinedString << "\n";
    }

    std::cout << "\nProgram complete.\n";

    return 0;
}