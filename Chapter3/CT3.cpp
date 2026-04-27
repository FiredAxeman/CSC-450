#include <iostream>

int main() {
    // 1. Create three different variables to store user input
    int val1, val2, val3;

    // Ask the user to enter three integer values
    std::cout << "Enter the first integer: ";
    std::cin >> val1;

    std::cout << "Enter the second integer: ";
    std::cin >> val2;

    std::cout << "Enter the third integer: ";
    std::cin >> val3;

    // 2. Create integer pointers to dynamic memory for each variable
    // The 'new int' dynamically allocates memory on the heap for an integer.
    int* ptr1 = new int;
    int* ptr2 = new int;
    int* ptr3 = new int;

    // Store the variable values into the newly allocated dynamic memory
    *ptr1 = val1;
    *ptr2 = val2;
    *ptr3 = val3;

    // 3. Display the contents of the variables
    std::cout << "\n--- Contents of Variables ---\n";
    std::cout << "Variable 1: " << val1 << "\n";
    std::cout << "Variable 2: " << val2 << "\n";
    std::cout << "Variable 3: " << val3 << "\n";

    // 4. Display the contents of the pointers
    // Printing the pointer with an asterisk (*) gives the value it points to (dereferencing).
    // Printing the pointer without the asterisk gives the memory address.
    std::cout << "\n--- Contents of Pointers ---\n";
    std::cout << "Pointer 1 points to value: " << *ptr1 << " (Stored at memory address: " << ptr1 << ")\n";
    std::cout << "Pointer 2 points to value: " << *ptr2 << " (Stored at memory address: " << ptr2 << ")\n";
    std::cout << "Pointer 3 points to value: " << *ptr3 << " (Stored at memory address: " << ptr3 << ")\n";

    // 5. Manage memory: Use the delete operator to free up the dynamically allocated memory
    delete ptr1;
    delete ptr2;
    delete ptr3;

    // Best Practice: Set pointers to nullptr after deleting to prevent "dangling pointers"
    ptr1 = nullptr;
    ptr2 = nullptr;
    ptr3 = nullptr;

    return 0;
}