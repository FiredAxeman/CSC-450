#include <iostream>
#include <limits>

int main() {
    short current_balance = 32700;
    short deposit = 100;
    std::cout << "--- Vulnerable Scenario ---" << std::endl;
    std::cout << "Starting Balance: " << current_balance << std::endl;
    std::cout << "Attempting to deposit: " << deposit << std::endl;
    current_balance = current_balance + deposit;
    std::cout << "New Balance (Overflowed): " << current_balance << std::endl;
    std::cout << "\n--- Mitigated Scenario ---" << std::endl;
    int safe_balance = 32700;
    int safe_deposit = 100;
    if (safe_balance > std::numeric_limits<int>::max() - safe_deposit) {
        std::cerr << "Error: Deposit would cause balance overflow!" << std::endl;
    } else {
        safe_balance = safe_balance + safe_deposit;
        std::cout << "New Safe Balance: " << safe_balance << std::endl;
    }

    return 0;
}