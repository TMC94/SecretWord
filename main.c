#include <stdio.h>
#include <stdlib.h>
#include "game.h"

/*
 * Author: Taylor Cotcamp
 * Date: December 13, 2018
 * File: main.c
 * Description: A game is played where the player must guess the
 * correct word to solve the puzzle.
 */

int main()
{
    /* Intro */
    printf("Let's play a game!\nGuess the 6-letter word using the following hint.\nThe answer is case-sensitive.\n");

    printf("\nHint: ");

    /* Retrieve the string from the hint file. */
    hint();

    /* Retrieve the answer */
    getAnswer();

    /* Accept user input */
    printf("\n\nEnter your guess here: ");
    scanf("%s", &guess);
    winCondition();

    /* Reveals the number of attempts completed. */
    while (gameLose() != 1)
    {
      printf("\n\nGuess #%d out of %d", numGuess, maxGuess);
      printf("\n");
      scanf("%s", &guess);
      winCondition();
    }

    /* End Game messages */
   if (gameEnd() == 1)
    printf ("\n\nCongratulations! You win!");
    else if (gameLose() == 1)
        printf ("\n\nYou lost the game!");

    return 0;
}
