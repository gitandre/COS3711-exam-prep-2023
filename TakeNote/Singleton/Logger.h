//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_LOGGER_H
#define TAKENOTE_LOGGER_H
#include <QObject>
#include <QString>
#include<QDebug>
#include <QDateTime>
#include "../FactoryAbstractPattern/TextModeFactory.h"

class Logger : public QObject {
    Q_OBJECT

    static inline  Logger* instance;
    Logger(QObject* parent = nullptr) : QObject(parent) {}
    TextModeFactory* textModeFactory;
public:
    static Logger* getInstance() {
        if (!instance) {
            instance = new Logger();
        }
        return instance;
    }

    void setTextModeFactory(TextModeFactory* factory) {
        textModeFactory = factory;
    }

    void logEvent(const QString& event) {

        /* ISO Date and Time: 'yyyy-MM-ddTHH:mm:ss'
        Output: '2023-10-20T05:10:23'

        Long Date, Short Time: 'dddd, MMMM d, yyyy h:mm AP'
        Output: 'Thursday, October 20, 2023 5:10 AM'

        Short Date, Long Time: 'MM/dd/yy h:mm:ss AP'
        Output: '10/20/23 5:10:23 AM'

        Only Date: 'yyyy-MM-dd'
        Output: '2023-10-20'

        Only Time: 'HH:mm:ss'
        Output: '05:10:23'

        Custom: 'yyyy/MM/dd -- HH::mm::ss'
        Output: '2023/10/20 -- 05::10::23'

        In these examples:

        yyyy stands for the 4-digit year.
        MM stands for the 2-digit month.
        dd stands for the 2-digit day.
        HH stands for the 2-digit hour (24-hour format).
        mm stands for the 2-digit minute.
        ss stands for the 2-digit second.
        AP stands for AM or PM.
        */


        TextOutputMode* mode = textModeFactory->getTextOutputMode();
        QString formattedText = mode->formatText(event);

        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        qDebug() << timestamp << ": " << formattedText;
    }
};


#endif //TAKENOTE_LOGGER_H
