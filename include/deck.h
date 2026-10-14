#ifndef DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define DECK_H
#define DECK_SIZE 52
#define SUITS 4
#define CARDS_NUM 13

struct Card_t{
     char title;
     char suit[4];
};
 
void GenerateDeck(struct Card_t ** deck, char * cardTitle, char ** cardSuit);
void ViewDeck(struct Card_t ** deck, int deckSize);
void DeleteDeck(struct Card_t ** deck, int deckSize);
void RandomizeDeck(struct Card_t ** deck, int deckSize);
int AllocateDeck(struct Card_t ** deck);

#endif
