# Hangman Game By Ezequiel Buck
# Texas Tech University
# Computational Thinking With Data Science
# January 25, 2023

def isValidGuess(guess):
    if len(guess) == 0:
        return "\nYour guess can't be empty"

    elif guess.isspace():
        return "\nYour guess can't be a space"

    elif len(guess) > 1:
        return "\nPlease type only 1 letter"

    elif guess in userTries:
        return "\nYou have already tried that letter"

    elif not guess.isalnum():
        return "\nYour guess can't be a symbol"

    elif guess.isdigit():
        return "\nYour guess can't be a number"

    else:
        return True


def findIndices(listToCheck, itemsToFind):
    indices = []
    for index, value in enumerate(listToCheck):
        if value == itemsToFind:
            indices.append(index)

    return indices


word = "airplane"
wordList = list(word)
lettersDiscovered = ['_', '_', '_', '_', '_', '_', '_', '_']
lettersMissing = ['a', 'i', 'r', 'p', 'l', 'n', 'e']
wordDiscovered = ''.join(lettersDiscovered)
attemptsLeft = 10
userTries = []

print("\nWelcome to the Hangman Game!! Hope you enjoy\n")

while attemptsLeft > 0 and wordDiscovered != word:

    # Status of the game
    print(f"{wordDiscovered} {attemptsLeft} attempts left.")

    # User Input
    while True:
        userGuess = input("Enter a letter: ").lower()

        # Validating the user's guess
        validationResult = isValidGuess(userGuess)
        if validationResult is True:
            userTries.append(userGuess)
            break
        else:
            print(validationResult)

    # Checking if the user guessed a letter
    if userGuess in lettersMissing:
        print("\nCorrect!!")

        # Removing that character from lettersMissing
        lettersMissing.pop(lettersMissing.index(userGuess))

        # Loop through the indices to assign the value(s) to lettersDiscovered
        indexValue = findIndices(wordList, userGuess)
        for i in indexValue:
            lettersDiscovered[i] = userGuess

        # Updating wordDiscovered
        wordDiscovered = ''.join(lettersDiscovered)
    else:
        print("\nIncorrect :(")
        attemptsLeft -= 1

if wordDiscovered == word:
    print(f"\nThe word was \"{word}\"")
    print("You are safe!!")

if attemptsLeft == 0:
    print("\nYou are dead :(")
