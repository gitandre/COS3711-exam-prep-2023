//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_TEXTOUTPUTMODE_H
#define TAKENOTE_TEXTOUTPUTMODE_H


#include <QString>

class TextOutputMode {
public:
    virtual QString formatText(const QString& text) = 0;
};


#endif //TAKENOTE_TEXTOUTPUTMODE_H
