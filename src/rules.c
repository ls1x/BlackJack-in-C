#include "../include/rules.h"

bool CheckLoseCondition(int * playerHandValue){
    if (playerHandValue[0] == playerHandValue[1] && playerHandValue[1] > 21){
        return true;
    } else if (playerHandValue[0] > 21 && playerHandValue[1] > 21){
        return true;
    } else {
        return false;
    }
}

bool AI(int * houseHandValue){
    if (houseHandValue[0] == 21 || houseHandValue[1] == 21){
        return false;
    } else if (houseHandValue[0] <= 13 || houseHandValue[1] <= 13){
        return true;
    } else {
        return false;
    }
}

int CheckWhoWon(int * playerHandValue, int * houseHandValue){
    bool playerBlackJack = false;
    bool houseBlackJack = false;
    int truePlayerHand = 0;
    int trueHouseHand = 0;
    if (playerHandValue[0] == 21 || playerHandValue[1] == 21){
        playerBlackJack = true; 
    }
    if (houseHandValue[0] == 21 || houseHandValue[1] == 21){
        houseBlackJack = true;
    }
    if (playerBlackJack == true && houseBlackJack == true){
        return 3;     
    }
    if (playerHandValue[0] == playerHandValue[1]){
        truePlayerHand = playerHandValue[0];
    } else if (playerHandValue[0] > 21){
        truePlayerHand = playerHandValue[1];
    } else {
        truePlayerHand = playerHandValue[0];
    }
    if (houseHandValue[0] == houseHandValue[1]){
        trueHouseHand = houseHandValue[0];
    } else if (houseHandValue[0] > 21){
        trueHouseHand = houseHandValue[1];
    } else {
        trueHouseHand = houseHandValue[0];
    }
    if (truePlayerHand > 21){
        return 2;
    } else if (trueHouseHand > 21){
        return 1;
    }
    if (playerBlackJack == false && houseBlackJack == false){
        if (truePlayerHand > trueHouseHand){
            return 1;
        } else if (trueHouseHand > truePlayerHand) {
            return 2;
        } else {
            return 3;
        }
    } else if (playerBlackJack == true){
        return 1;
    } else if (houseBlackJack == true){
        return 2;
    }
}
