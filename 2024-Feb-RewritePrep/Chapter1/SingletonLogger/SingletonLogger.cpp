//
// Created by User on 2/9/2024.
//

#include <chrono>
#include <iomanip>
#include "SingletonLogger.h"



SingletonLogger::~SingletonLogger() {

}

SingletonLogger::SingletonLogger(){

}

std::string SingletonLogger::getCurrentTimestamp(){
    // Get the current system time
    auto now = std::chrono::system_clock::now();

    // Convert the system time to a time_point in local time
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    // Convert the time_point to a struct tm (timeinfo)
    std::tm timeinfo = *std::localtime(&time);

    // Format the timestamp as a string
    std::stringstream ss;
    ss << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

SingletonLogger &SingletonLogger::getInstance() {
    static SingletonLogger instance;
    return instance;
}

void SingletonLogger::log(const string& message) {

    string logMsg = "[LOG] " + getCurrentTimestamp() + " | " + message + "\n";
    m_logs.push_back(logMsg);
    cout << logMsg;
}

void SingletonLogger::getLogs() {
    cout << "I am printing the logs" << endl;
    for(const auto& logMsg: m_logs){
        cout << logMsg;
    }
}


