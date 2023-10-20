//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_ALLCAPSMODEFACTORY_H
#define TAKENOTE_ALLCAPSMODEFACTORY_H


#include "TextModeFactory.h"
#include "TextOutputMode.h"
#include "AllCapsMode.h"

class AllCapsModeFactory : public TextModeFactory {
public:
    TextOutputMode* getTextOutputMode() override {
        return new AllCapsMode();
    }
};


#endif //TAKENOTE_ALLCAPSMODEFACTORY_H
