//
// Created by User on 2/9/2024.
//

#include "Sender.h"
#include <iostream>
#include <random>

int Sender::generateRandomNumber(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd()); // Mersenne Twister engine

    // Uniform distribution in range [1, 100]
    std::uniform_int_distribution<> distrib(a, b);

    // Generate and print a random integer
    int randomInt = distrib(gen);
    return randomInt;

}
void Sender::sendSomething() {

    int rando = generateRandomNumber();

    for(int i = 0; i <= rando;i++){
        emit mySignal(i);
    }

}


