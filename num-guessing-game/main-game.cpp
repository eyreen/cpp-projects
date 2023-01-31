#include "../test.h"
#include "Game.h"


TEST(TestGenerateNumberToGuess)
{
    for (int i=0; i<10; ++i)
    {
        int number = generateNumberToGuess();
        check(number >= 1 && number <= 100);
    }
}

TEST(TestNumber)
{
    check(testNumber(9, 10), false);
    check(testNumber(11, 10), false);
    check(testNumber(10, 10), true);
}

TEST(TestNumberInRange)
{
    check(numberIsInRange(0), false);
    check(numberIsInRange(1), true);
    check(numberIsInRange(100), true);
    check(numberIsInRange(101), false);
}

int main()
{
    bool foundCorrectAnswer = false;
    const int numberToGuess = generateNumberToGuess();
    while (! foundCorrectAnswer)
    {
        int userInput = getUserInput();
        foundCorrectAnswer = testNumber(userInput, numberToGuess);
    }
}