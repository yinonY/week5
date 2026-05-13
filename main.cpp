#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx; // creating the mutex lock

void print_message(int id) {
    // making the lock guard to automatically release the lock when the function ends
    std::lock_guard<std::mutex> guard(mtx);
    
    std::cout << "thread says kawabanga" << id << std::endl;
}

int main() {
    std::vector<std::thread> threads;
    
    // making 5 threads to print the message
    for (int i = 0; i < 5; ++i) {
        threads.push_back(std::thread(print_message, i));
    }
    
    // joining the threads to the main thread
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
    
    return 0;
}