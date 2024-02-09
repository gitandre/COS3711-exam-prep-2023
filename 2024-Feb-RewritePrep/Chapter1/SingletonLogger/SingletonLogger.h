//
// Created by User on 2/9/2024.
//

#ifndef CHAPTER1_SINGLETONLOGGER_H
#define CHAPTER1_SINGLETONLOGGER_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SingletonLogger: public QObject {
    Q_OBJECT

public:

    enum class LogLevel {
        ERROR,
        DEBUG,
        WARNING,
        SUCCESS
    };

    // Static member function to access the singleton instance
    static SingletonLogger &getInstance();

    // Logging function
    void log(string message);
    void log(LogLevel level, string message);

    void getLogs();





    // Private constructor to prevent external instantiation
    SingletonLogger();

    // Private destructor to prevent deletion through pointers
    ~SingletonLogger();

public slots:
    static void mySlot();

private:

    std::string getCurrentTimestamp();

    vector<string> m_logs;

    vector<QObject*> m_qObjects;

    // Helper function to convert LogLevel enum to string
    static string logLevelToString(LogLevel level) {
        switch (level) {
            case LogLevel::ERROR: return "ERROR";
            case LogLevel::DEBUG: return "DEBUG";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::SUCCESS: return "SUCCESS";
            default: return "UNKNOWN";
        }
    }


};


#endif //CHAPTER1_SINGLETONLOGGER_H
