//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_ALLCAPSMODE_H
#define TAKENOTE_ALLCAPSMODE_H


#include <QString>
#include "TextOutputMode.h"

class AllCapsMode : public TextOutputMode {
public:
    QString formatText(const QString& text) override {
        return text.toUpper();
    }
};


#endif //TAKENOTE_ALLCAPSMODE_H
