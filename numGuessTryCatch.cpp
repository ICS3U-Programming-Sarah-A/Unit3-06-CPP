// Copyright (c) 2022 Sarah All rights reserved.
//
// Created by: Sarah
// Created on: Apr 5th, 2022
// This program asks the user to  guess a number. It then generates a
// random number. If the random number is equal to the number guess, you win.
// If not, you lose. It also checks to see if user entered a valid number.

#include <iostream>
#include <random>
#include <string>

int main() {
    // Generates random number
    int randomNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,100]
    randomNumber = idist(rgen);
    // std::cout << randomNumber << std::endl;
    // declare variables
    std::string numberGuessAsString;
    int numberGuessAsInt;

    // get number guessed from user
    std::cout << "Enter a number between 0 and 9: ";
    std::cin >> numberGuessAsString;
    std::cout << "" << std::endl;

    try {
        // convert the user's guess from string to an int
        numberGuessAsInt = std::stoi(numberGuessAsString);
        std::cout << "" << std::endl;

        // check if the number guess is the same as random number
        if (numberGuessAsInt == randomNumber) {
            std::cout << "Your guess is correct";
        } else {
            std::cout << "Incorrect, the correct number is " \
            << randomNumber << "\n";
    }

        // checks to see if user entered a valid number
    } catch (std::invalid_argument) {
        // user did not enter an integer.
        std::cout << numberGuessAsString << " is not a number\n";
        std::cout << "" << std::endl;
    }
}
