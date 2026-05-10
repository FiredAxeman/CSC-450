#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to append user input to a specified file
void appendToFile(const std::string& filename, const std::string& inputData) {
    // Open the file in append mode (std::ios::app) so existing data is not deleted
    std::ofstream outFile(filename, std::ios::app);

    if (outFile.is_open()) {
        outFile << inputData << "\n";
        outFile.close();
        std::cout << "Success: Data appended to " << filename << std::endl;
    } else {
        std::cerr << "Error: Could not open " << filename << " for appending." << std::endl;
    }
}

// Function to read a file, reverse all its characters, and save to a new file
void reverseFileContent(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inFile(inputFilename);

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open " << inputFilename << " for reading." << std::endl;
        return;
    }

    // Read the entire contents of the file into a single string using stream iterators
    std::string fileContent((std::istreambuf_iterator<char>(inFile)),
                             std::istreambuf_iterator<char>());
    inFile.close();

    // Reverse the entire string in memory
    std::reverse(fileContent.begin(), fileContent.end());

    // Write the reversed string to the output file
    std::ofstream outFile(outputFilename);

    if (outFile.is_open()) {
        outFile << fileContent;
        outFile.close();
        std::cout << "Success: Reversed content saved to " << outputFilename << std::endl;
    } else {
        std::cerr << "Error: Could not open " << outputFilename << " for writing." << std::endl;
    }
}

int main() {
    // Define the filenames based on the requirements
    const std::string originalFile = "CSC450_CT5_mod5.txt";
    const std::string reversedFile = "CSC450-mod5-reverse.txt";
    std::string userInput;

    // 1. Obtain input from the user
    std::cout << "Enter the text you want to append to the file:\n> ";
    std::getline(std::cin, userInput);

    // 2. Append the user input to the original text file
    appendToFile(originalFile, userInput);

    // 3. Reverse the characters of the original file and store in the new file
    reverseFileContent(originalFile, reversedFile);

    return 0;
}