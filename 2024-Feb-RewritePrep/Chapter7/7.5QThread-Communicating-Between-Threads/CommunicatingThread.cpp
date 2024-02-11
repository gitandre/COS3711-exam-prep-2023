// CommunicateThread.cpp
#include "CommunicatingThread.h"

void CommunicatingThread::run() {

    for (int i = 0; i < 5; ++i) {
        emit sendValue(i, m_name);
    }
}