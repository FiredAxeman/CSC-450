#include <iostream>
#include <string>
#include <iomanip>

// RISK 1: Log Injection Vulnerability
void logUserAction(const std::string& username, const std::string& action) {
    // Vulnerable: Outputting user input directly to the stream without sanitization
    std::cout << "[LOG] User: " << username << " performed action: " << action << "\n";
}

// RISK 2: Formatting State Leak
void printMemoryAddress(unsigned int address) {
    // Vulnerable: std::hex alters the persistent state of std::cout.
    // We did not save or restore the original formatting flags.
    std::cout << "[SYSTEM] Address accessed: 0x" << std::hex << address << "\n";
}
void printMemoryAddressSafe(unsigned int address) {
    // Save the current formatting state
    std::ios_base::fmtflags original_flags = std::cout.flags();

    std::cout << "[SYSTEM] Address accessed: 0x" << std::hex << address << "\n";

    // Restore the formatting state
    std::cout.flags(original_flags);
}
int main() {
    std::cout << "--- 1. Log Injection Demonstration ---\n";
    // A normal user logs in
    logUserAction("alice", "login");

    // A malicious user injects newline characters to forge a fake log entry
    std::string malicious_input = "bob\n[LOG] User: admin performed action: delete_database";
    logUserAction(malicious_input, "login");


    std::cout << "\n--- 2. Formatting State Leak Demonstration ---\n";
    printMemoryAddress(255); // 255 becomes 'ff'

    // Because std::hex is persistent, subsequent integer output is corrupted.
    int unread_messages = 10;

    // This will print "You have a new messages" instead of "You have 10 new messages"
    std::cout << "[INFO] You have " << unread_messages << " new messages.\n";

    return 0;
}
