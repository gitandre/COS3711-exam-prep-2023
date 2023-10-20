//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_NORMALMODE_H
#define TAKENOTE_NORMALMODE_H


#include <QString>
#include "TextOutputMode.h"

class NormalMode : public TextOutputMode {
public:
    QString formatText(const QString& text) override {
        return text;
    }
};


#endif //TAKENOTE_NORMALMODE_H
