#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isValidGuess(char, char *, int *);

int main()
{
    const char word[] = "airplane";
    char lettersMissing[] = "airplne";
    char wordDiscovered[] = "________";
    char userTries[26];
    int userTriesCount = 0;
    int attemptsLeft = 10;
    char userGuess;
    bool checker;
    bool result;

    printf("\nWelcome to the Hangman Game!! Hope you enjoy\n");

    while (attemptsLeft > 0 && strcmp(wordDiscovered, word) != 0)
    {
        // Status of the game
        printf("\n%s %d attempts left.\n", wordDiscovered, attemptsLeft);

        // User input
        do
        {
            printf("Enter a letter: ");
            scanf(" %c", &userGuess);

            result = isValidGuess(userGuess, userTries, &userTriesCount);

        } while (result != true);
        userGuess = tolower(userGuess);

        // Checking if user guessed a letter
        checker = false;
        for (int i = 0; i < strlen(lettersMissing); i++)
        {
            if (userGuess == lettersMissing[i])
            {
                checker = true;
                printf("\nCorrect!!");

                // Removing that character from lettersMissing
                for (int j = 0; j < strlen(lettersMissing); j++)
                    if (userGuess == lettersMissing[j])
                        memmove(&lettersMissing[j], &lettersMissing[j + 1], (strlen(lettersMissing) - j) + 1);

                // Loop through the indices to assign the value(s) to lettersDiscovered
                for (int k = 0; k < strlen(word); k++)
                    if (userGuess == word[k])
                        wordDiscovered[k] = userGuess;

                break;
            }
        }

        if (checker == false)
        {
            printf("\nIncorrect");
            attemptsLeft--;
        }
    }

    if (strcmp(wordDiscovered, word) == 0)
        printf("\nYou are safe!!\nThe word was \"%s\"\n", word);

    if (attemptsLeft == 0)
        printf("\nYou are dead :(\nThe word was \"%s\"\n", word);

    return 0;
}

bool isValidGuess(char guess, char *userTries, int *userTriesCount)
{
    int bufferChar = getchar();

    if (bufferChar != '\n')
    {
        printf("\nINVALID INPUT. Please enter a single alphabetic letter\n");
        fflush(stdin); // Clear Buffer
        return false;
    }

    if (!isalpha(guess))
    {
        printf("\nINVALID INPUT. Please enter a single alphabetic letter\n");
        return false;
    }

    for (int i = 0; i < *userTriesCount; i++)
    {
        if (guess == userTries[i])
        {
            printf("\nYou have already tried that letter\n");
            return false;
        }
    }

    userTries[*userTriesCount] = guess;
    (*userTriesCount)++;

    return true;
}
