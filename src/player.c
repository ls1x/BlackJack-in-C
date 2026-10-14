#include "../include/player.h"

int DrawFirstHand(struct Card_t ** deck, struct Card_t ** player, int * deckSize){
    int dSize = *deckSize-1;
    player[0]->title = deck[dSize]->title; 
    strncpy(player[0]->suit, deck[dSize]->suit, 4);
    player[1]->title = deck[dSize-1]->title; 
    strncpy(player[1]->suit, deck[dSize-1]->suit, 4); 
    for (int i = 0; i < PLAYER_STARTING_HAND; i++){
        free(deck[dSize-i]);
        deck[dSize-i] = NULL;
    }
    *deckSize = *deckSize - PLAYER_STARTING_HAND;
    return 0;
}

int AllocatePlayer(struct Card_t ** player){
    for (int i = 0; i < PLAYER_STARTING_HAND; i++){
        if ((player[i] = calloc(1,sizeof(struct Card_t))) == NULL){
            perror("[ERR-Calloc]");
            return -1;
        }
    }
    printf("[+] Player Hand Created\n");
    return 0;
}

int DrawCard(struct Card_t ** deck, struct Card_t *** player, int * deckSize, int * handSize){
    /* Explaining Triple Pointers:
     * - When using realloc() you need to have the address of the memory you want to change
     * - So if I want to reallocate Card_t ** player I will need access to Card_t *** player
     * - It looks complicated but the reason is simple.
     */
    int dSize = *deckSize-1;
    int hSize = *handSize-1;
    size_t newSize = (*handSize+1) * sizeof(struct Card_t *);
    struct Card_t ** temp = NULL;
    temp = realloc(*player, newSize);
    if (temp == NULL){
        perror("[ERR-Realloc]");
        free(player);
        return -1;
    } else {
        *player = temp;
    }
    (*player)[*handSize] = calloc(1,sizeof(struct Card_t));
    if ((*player)[*handSize] == NULL){
        perror("[ERR-Calloc]");
        return -1;
    }
    (*player)[*handSize]->title = deck[dSize]->title;
    strncpy((*player)[*handSize]->suit, deck[dSize]->suit, 4);
    free(deck[dSize]);
    deck[dSize] = NULL;
    *handSize = *handSize + 1;
    *deckSize = *deckSize - 1;
    return 0;
}

void ViewPlayerHand(struct Card_t ** player, int handSize, bool isPlayer){
    printf("[+] ");
    for (int i = 0; i < handSize; i++){
        if (player[i]->title == 'X'){
            if (isPlayer == false && i == 0){
                printf("[?][?] ");
            } else {
                printf("[%s][10] ", player[i]->suit);
            }
        } else {
            if (isPlayer == false && i == 0){
                printf("[?][?] ");
            } else {
                printf("[%s][%c] ", player[i]->suit, player[i]->title);
            }
        }
    }
    printf("\n");
    return;
}

void DeletePlayer(struct Card_t ** player, int handSize){
    for (int i = 0; i < handSize; i++){
        free(player[i]);
    }
    free(player);
    return;
}

void CalculateHandValue(struct Card_t ** player, int handSize, int * handValue, bool isDebug){
    handValue[0] = 0;
    handValue[1] = 0;
    for (int i = 0; i < handSize; i++){
        if (player[i]->title == 'X' || player[i]->title == 'J' || player[i]->title == 'Q' || player[i]->title == 'K'){
            handValue[0] += 10;
            handValue[1] += 10;
        } else if (player[i]->title == 'A'){
            handValue[0] += 11;
            handValue[1] += 1;
        } else {
            // To convert char to int
            handValue[0] += player[i]->title - '0';
            handValue[1] += player[i]->title - '0';
        }
    }
    if (isDebug == true){
        printf("[+] Hand Value: %d | %d\n", handValue[0], handValue[1]);
    }
    return;
}
