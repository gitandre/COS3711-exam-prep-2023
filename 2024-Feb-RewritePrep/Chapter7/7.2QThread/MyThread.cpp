// MyThread.cpp
#include "MyThread.h"
#include <QTime>



void MyThread::run() {
    for (int i = 0; i <= m_val; ++i) {
        QTime delay = QTime::currentTime().addMSecs(m_val * 250);
        while (QTime::currentTime() < delay) {
            // do nothing and wait
        }
        emit progress(i);
    }
}