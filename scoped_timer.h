#ifndef SCOPED_TIMER
#define SCOPED_TIMER

#include <string>
#include <chrono>
#include <iostream>

class ScopedTimer{
    public:
    ScopedTimer(std::string name = "unnamed_timer"){
        name_ = name;
        startTime_ = std::chrono::high_resolution_clock::now();
    }

    ~ScopedTimer(){
        std::chrono::duration<double> elapsedTime = std::chrono::high_resolution_clock::now() - startTime_;
        auto elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime);
        std::cout << "Elapsed time for " << name_ << ":" << elapsedMilliseconds.count() << "\n";
    }

    private:
    std::string name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime_;
};

#endif