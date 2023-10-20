//
// Created by User on 10/20/2023.
//

#ifndef TAKENOTE_TEXTMODEFACTORY_H
#define TAKENOTE_TEXTMODEFACTORY_H


#include "TextOutputMode.h"

class TextModeFactory {
public:
    virtual TextOutputMode* getTextOutputMode() = 0;
};


#endif //TAKENOTE_TEXTMODEFACTORY_H
