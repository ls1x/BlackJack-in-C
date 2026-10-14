# Blackjack CLI

A command-line implementation of the classic Blackjack card game written in C.

This project was developed as a programming exercise to practice low-level programming concepts such as dynamic memory management, pointers, modular design, and game logic. The game is played entirely in the terminal against a computer-controlled dealer.

---

## Features

* Standard 52-card deck
* Randomized deck every game
* Unicode card suits (♠ ♥ ♦ ♣)
* Player versus computer dealer
* Hit and Stand actions
* Automatic hand value calculation
* Simple dealer AI
* Dynamic memory allocation
* Modular project structure
* Terminal-based interface

---

## Project Structure

```text
.
├── bin/            # Generated executable
├── include/        # Header files
├── obj/            # Object files
├── src/            # Source files
├── Makefile
└── README.md
```

---

## Building

Compile the project with:

```bash
make
```

The executable will be generated in:

```text
bin/BlackJack.out
```

---

## Running

The easiest way to build and run the project is:

```bash
make run
```

Alternatively, if the project has already been compiled:

```bash
./bin/BlackJack.out
```

---

## Gameplay

At the beginning of the game, both the player and the dealer receive two cards.

During the player's turn, choose one of the available actions:

| Input | Action |
| ----: | ------ |
|   `1` | Stand  |
|   `2` | Hit    |

If the player stands, the dealer automatically plays according to its decision logic. When both turns are complete, the game compares the hands and announces the winner.

---

## Rules

* Cards 2–10 are worth their face value.
* J, Q, and K are worth 10 points.
* Aces are evaluated during hand calculation.
* Exceeding 21 results in an immediate bust.
* The hand closest to 21 wins.
* Equal hand values result in a draw.

---

## Technical Highlights

This project demonstrates several fundamental C programming concepts:

* Dynamic memory allocation (`malloc`, `calloc`, `realloc`, `free`)
* Pointer manipulation
* Multi-level pointers
* Modular programming using header files
* Custom data structures
* Random number generation
* Terminal user interaction
* Resource cleanup

One interesting aspect of the implementation is that player hands grow dynamically during gameplay, requiring memory to be resized whenever a new card is drawn.
