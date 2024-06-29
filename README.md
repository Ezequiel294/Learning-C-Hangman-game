# Hangman Game in C and Python

This repository contains two versions of the classic Hangman game which i wrote to practice and understand programming concepts in both C and Python. Below you will find instructions on how to compile and run each version of the game.

## Prerequisites

Before running the programs, ensure you have the following installed:

- GCC compiler for compiling C code.
- Python interpreter for running Python scripts.

### For Linux Users

- GCC can be installed using your distribution's package manager. For example, on Ubuntu, you can install it by running `sudo apt-get install build-essential`.
- Python can also be installed via your package manager. For example, on Ubuntu, use `sudo apt-get install python3`.

### For Windows Users

- Download and install the GCC compiler from [MinGW](https://www.mingw-w64.org/) or another preferred source.
- Install Python from the [official Python website](https://www.python.org/downloads/).

## Running the C Version

1. Open a terminal or command prompt.
2. Navigate to the directory containing the `main.c` file.
3. Compile the C program using GCC by running the following command:

4. Run the compiled program:
- On Linux, use `./hangman`.
- On Windows, just type `hangman` and press Enter.

## Running the Python Version

1. Open a terminal or command prompt.
2. Navigate to the directory containing the `main.py` file.
3. Run the Python script by executing:
```bash
python3 main.py
```

## Game Instructions

- Once the game starts, you will be prompted to guess a letter in the word.
- You have a limited number of attempts to guess the word correctly.
- Each incorrect guess will reduce the number of attempts left.
- The game ends when you either guess the word correctly or run out of attempts.