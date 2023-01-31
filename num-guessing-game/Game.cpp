#include "Game.h"

#include <cstdlib>
#include <iostream>

int generateNumberToGuess()
{
    return (std::rand() % 100) + 1;
}

bool numberIsInRange(int i)
{
    return i >= 1 && i <= 100;
}

int getUserInput()
{
    bool hasValidInput = false;
    int userInput = 0;
    while (!hasValidInput)
    {
        std::cout << "Please enter a number between 1 and 100: ";
        std::cin >> userInput;

        if (numberIsInRange(userInput))
        {
            hasValidInput = true;
        }
        else
        {
            std::cout << "The number you entered is out of range!" << std::endl;
        }
    }
    return userInput;
}

bool testNumber(int number, int numberToGuess)
{
    if (number > numberToGuess)
    {
        std::cout << "The number you entered is too large." << std::endl;
        return false;
    }
    else if (number < numberToGuess)
    {
        std::cout << "The number you entered is too small." << std::endl;
        return false;
    }
    else // number == numberToGuess
    {
        std::cout << "You found the correct answer!" << std::endl;
        return true;
    }
}
