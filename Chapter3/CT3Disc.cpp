#include <iostream>

int main() {
    // 1. Using Address-of (&) and Dereference (*) with a single variable
    int singleVar = 42;
    int* singlePtr = &singleVar; // Address-of operator (&) gets the memory location

    std::cout << "Value of singleVar: " << singleVar << "\n";
    std::cout << "Address of singleVar: " << singlePtr << "\n";

    // Dereferencing the pointer to change the original variable's value
    *singlePtr = 100;
    std::cout << "New value of singleVar (changed via pointer): " << singleVar << "\n\n";

    // 2. Pointers and Arrays
    int numbers[3] = {10, 20, 30};

    // The array name 'numbers' acts as a pointer to the first element
    int* arrayPtr = numbers;

    std::cout << "Array elements using pointer arithmetic:\n";
    for (int i = 0; i < 3; i++) {
        // Dereference the pointer, then move to the next memory block
        std::cout << "Element " << i << ": " << *arrayPtr << "\n";
        arrayPtr++; // Pointer arithmetic moves to the next integer
    }

    return 0;
}