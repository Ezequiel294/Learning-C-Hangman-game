#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    const char word[] = "airplane";
    char lettersMissing[] = "airplne";
    char wordDiscovered[] = "________";
    int attemptsLeft = 10;
    char userGuess;
    bool checker;

    printf("\nWelcome to the Hangman Game!! Hope you enjoy\n");

    while (attemptsLeft > 0 && strcmp(wordDiscovered, word) != 0)
    {
        // Status of the game
        printf("\n%s %d attempts left.\n", wordDiscovered, attemptsLeft);

        // User input
        printf("Enter a letter: ");
        scanf(" %c", &userGuess);
        userGuess = tolower(userGuess);

        // Checking if user guessed a letter
        checker = false;
        for (int i = 0; i < strlen(lettersMissing); i++)
        {
            if (userGuess == lettersMissing[i])
            {
                checker = true;
                printf("\nCorrect!!\n");

                // Removing that character from lettersMissing
                for (int j = 0; j < strlen(lettersMissing); j++)
                {
                    if (userGuess == lettersMissing[j])
                    {
                        memmove(&lettersMissing[j], &lettersMissing[j + 1], (strlen(lettersMissing) - j) + 1);
                    }
                }

                // Loop through the indices to assign the value(s) to lettersDiscovered
                for (int k = 0; k < strlen(word); k++)
                {
                    if (userGuess == word[k])
                    {
                        wordDiscovered[k] = userGuess;
                    }
                }

                break;
            }
        }

        if (checker == false)
        {
            printf("\nIncorrect\n");
            attemptsLeft--;
        }

    }

    if (strcmp(wordDiscovered, word) == 0)
    {
        printf("\nThe word was \"%s\"\n", word);
        printf("You are safe!!\n");
    }

    if (attemptsLeft == 0)
    {
        printf("\nYou are dead :(\n");
    }

    return 0;
}
