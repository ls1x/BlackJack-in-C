#ifndef PLAYER_H

#include "./deck.h"
#include <stdbool.h>

#define PLAYER_H
#define PLAYER_STARTING_HAND 2
#define DEBUG false

int DrawFirstHand(struct Card_t ** deck, struct Card_t ** player, int * deckSize);
int AllocatePlayer(struct Card_t ** player);
int DrawCard(struct Card_t ** deck, struct Card_t *** player, int * deckSize, int * handSize);
void CalculateHandValue(struct Card_t ** player, int handSize, int * handValue, bool isDebug);
void ViewPlayerHand(struct Card_t ** player, int handSize, bool isPlayer);
void DeletePlayer(struct Card_t ** player, int handSize);

#endif

