/*
     This is a number guessing program.

     EXAMPLE of how it works:
     Think of a number from 1 to 100, I can guess your number within logBase2(100 + 1 - 1) == 7 turns.
     (The Player is thinking of 81 e.g.)

     Is your number roundUp((100+1-1)/2) == 50? (Range: 1 - 100)
     No, my number is higher.

     Is your number roundUp((100+51-1)/2) ==  75? (Range 51 - 100)
     No, my number is higher.

     Is your number roundUp((100+76-1)/2) == 87.5== 88? (Range 76 - 100)
     No, my number is lower.

     Is your number roundUp((87+76-1)/2) ==  81?
     Yes, you guessed my number within 7 turns, specifically 4 turns.

*/

#include <stdio.h>
#include <math.h>

#define START 1
#define END 100

int main(void){

    int lowRange = START;
    int highRange = END;
    int possibleNumbers = highRange + lowRange - 1;                 // range of possible numbers left
    int maxQuestions = ceil(log(possibleNumbers) / log(2) );  // log base 2 of possible numbers rounded up

    printf("Choose a number between %d to %d in your mind.\n", lowRange, highRange);

    printf("We will guess it by asking less than %d questions.\n\n", maxQuestions + 1);

    int guess,
            count = 0,
            numTurns = 1;
    char symbol;

    do {
        count++;     // question counter
        possibleNumbers = highRange + lowRange - 1;     // update the new range of possible numbers left
        guess = ceil(possibleNumbers / 2.0);         // number we guess

        printf("Question %d: Is your number =, < or > %d?\n", count, guess);

        scanf("%c", &symbol);        // scan user's input
        while ((getchar()) != '\n');        // flushes the standard input (clears the input buffer)

        if(symbol == '>')
            lowRange = guess + 1;    // update the new low range
        else if(symbol == '<')
            highRange = guess - 1;   // update the new high range
        else if(symbol == '=')
            break;                   // break out of the loop, because we guessed the right number

        numTurns++;     // increment the number of turns

    } while(symbol != '=' && numTurns <= maxQuestions);

    if(numTurns > maxQuestions)
        printf("You made a mistake, you've exceeded the maximum number of turns.\n");
    else
        printf("I guessed your number in %d turns!\n", numTurns);

    return 0;
}