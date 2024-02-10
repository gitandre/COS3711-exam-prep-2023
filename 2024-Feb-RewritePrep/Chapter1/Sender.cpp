//
// Created by User on 2/9/2024.
//

#include "Sender.h"
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "SingletonLogger/SingletonLogger.h"

using namespace std;

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

    int max = 3;
    int counter = 0;
    while(counter <= max){

        int rando = generateRandomNumber(1,max);

        for(int i = 0; i <= rando;i++){

            emit mySignal( to_string(i));
        }

        this_thread::sleep_for(std::chrono::seconds(generateRandomNumber(1,5)));
        counter++;
    }

    delete this;
}



