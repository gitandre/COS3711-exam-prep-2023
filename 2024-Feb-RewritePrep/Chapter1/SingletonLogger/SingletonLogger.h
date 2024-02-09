//
// Created by User on 2/9/2024.
//

#ifndef CHAPTER1_SINGLETONLOGGER_H
#define CHAPTER1_SINGLETONLOGGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SingletonLogger {

public:
    // Static member function to access the singleton instance
    static SingletonLogger& getInstance();

    // Logging function
    void log(const string& message);

    void getLogs();

    // Private constructor to prevent external instantiation
    SingletonLogger();
    // Private destructor to prevent deletion through pointers
    ~SingletonLogger();


private:

    std::string getCurrentTimestamp();

    vector<string> m_logs;
};


#endif //CHAPTER1_SINGLETONLOGGER_H
