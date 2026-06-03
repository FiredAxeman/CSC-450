#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>

// Global synchronization primitives
std::mutex mtx;
std::condition_variable cv;
bool thread1_done = false;

// Function for Thread 1
void countUp(const std::string& threadName) {
    for (int i = 0; i <= 20; ++i) {
        // Output is synchronized implicitly here by the fast loop,
        // but in larger apps, cout should be locked to prevent interleaved characters.
        std::cout << threadName << " counting up: " << i << std::endl;
    }

    // Lock the mutex before modifying the shared state
    std::unique_lock<std::mutex> lock(mtx);
    thread1_done = true;

    // Notify the waiting thread
    cv.notify_one();
}

// Function for Thread 2
void countDown(const std::string& threadName) {
    // Lock the mutex and wait for Thread 1 to finish
    std::unique_lock<std::mutex> lock(mtx);

    // The lambda function protects against "spurious wakeups"
    cv.wait(lock, []{ return thread1_done; });

    // Once woken up and thread1_done is true, proceed with counting down
    for (int i = 20; i >= 0; --i) {
        std::cout << threadName << " counting down: " << i << std::endl;
    }
}

int main() {
    std::cout << "Starting concurrent counter application...\n\n";

    std::string name1 = "Thread 1";
    std::string name2 = "Thread 2";

    // Launch both threads concurrently
    std::thread t1(countUp, name1);
    std::thread t2(countDown, name2);

    // Wait for both threads to finish execution before exiting main
    t1.join();
    t2.join();

    std::cout << "\nApplication finished successfully.\n";
    return 0;
}