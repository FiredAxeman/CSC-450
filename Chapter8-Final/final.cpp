#include <iostream>
#include <thread>
#include <chrono>

// Function for Thread 1: Counts up from 0 to 20
void countUp() {
    std::cout << "Thread 1 starting...\n";
    for (int i = 0; i <= 20; ++i) {
        std::cout << "Thread 1: " << i << "\n";
        // Slight delay to simulate processing time
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Thread 1 finished.\n";
}

// Function for Thread 2: Counts down from 20 to 0
void countDown() {
    std::cout << "Thread 2 starting...\n";
    for (int i = 20; i >= 0; --i) {
        std::cout << "Thread 2: " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Thread 2 finished.\n";
}

int main() {
    try {
        // Start Thread 1 and wait for it to finish
        std::thread thread1(countUp);
        thread1.join();

        // Start Thread 2 and wait for it to finish
        std::thread thread2(countDown);
        thread2.join();

    } catch (const std::exception& e) {
        std::cerr << "An error occurred during thread execution: " << e.what() << "\n";
        return 1;
    }

    std::cout << "Application completed successfully.\n";
    return 0;
}