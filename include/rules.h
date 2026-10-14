#ifndef RULES_H

#include "./player.h"
#include <stdbool.h>

bool CheckLoseCondition(int * playerHandValue);
bool AI(int * houseHandValue);
int CheckWhoWon(int * playerHandValue, int * houseHandValue);

#endif
