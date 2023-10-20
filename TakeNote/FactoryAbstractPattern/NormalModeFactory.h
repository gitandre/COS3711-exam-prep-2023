//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_NORMALMODEFACTORY_H
#define TAKENOTE_NORMALMODEFACTORY_H


#include "TextModeFactory.h"
#include "NormalMode.h"

class NormalModeFactory : public TextModeFactory {
public:
    TextOutputMode* getTextOutputMode() override {
        return new NormalMode();
    }
};


#endif //TAKENOTE_NORMALMODEFACTORY_H
