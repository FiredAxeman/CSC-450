#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>

class SafeLogger {
private:
    std::mutex mtx;
    std::vector<std::string> logs;

public:
    void addLog(const std::string& message, int threadId) {
        // Use std::scoped_lock to ensure the mutex is released
        // even if an exception occurs within this scope.
        std::scoped_lock lock(mtx);

        std::string entry = "Thread " + std::to_string(threadId) + ": " + message;
        logs.push_back(entry);

        // Mutex is automatically released here when 'lock' goes out of scope.
    }

    void printLogs() {
        std::scoped_lock lock(mtx);
        for (const auto& log : logs) {
            std::cout << log << std::endl;
        }
    }
};

void work(int id, SafeLogger& logger) {
    for (int i = 0; i < 3; ++i) {
        logger.addLog("Processing task " + std::to_string(i), id);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    SafeLogger logger;
    std::vector<std::thread> threads;

    // Launching multiple threads accessing the same logger object
    for (int i = 1; i <= 5; ++i) {
        threads.emplace_back(work, i, std::ref(logger));
    }

    // Join threads to ensure main doesn't exit prematurely
    for (auto& t : threads) {
        t.join();
    }

    logger.printLogs();
    return 0;
}