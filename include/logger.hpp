#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <mutex>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        logfile_ << message << std::endl;
    }

private:
    Logger() {
        logfile_.open("app.log", std::ios::app);
    }
    ~Logger() {
        if (logfile_.is_open()) {
            logfile_.close();
        }
    }
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::ofstream logfile_;
    std::mutex mutex_;
};

#endif // LOGGER_HPP
