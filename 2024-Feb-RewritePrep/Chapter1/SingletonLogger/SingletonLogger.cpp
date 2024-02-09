//
// Created by User on 2/9/2024.
//

#include "SingletonLogger.h"



SingletonLogger::~SingletonLogger() {

}

SingletonLogger::SingletonLogger(){

}

SingletonLogger &SingletonLogger::getInstance() {
    static SingletonLogger instance;
    return instance;
}

void SingletonLogger::log(const string& message) {

    m_logs.push_back(message);
    cout << "[LOG] " << message << endl;
}

void SingletonLogger::getLogs() {
    cout << "I am printing the logs" << endl;
    for(const auto& message: m_logs){
        cout << "[LOG] " << message << endl;
    }
}
