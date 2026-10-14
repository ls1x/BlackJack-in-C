#include "../include/view.h"

void PrintView(struct Card_t ** player, int handSize, int * handValue){
    bool isPlayer = true;
    printf("\033c" );
    printf("$ --- Welcome to the BlackJack King --- $\n");
    printf("[+] Your Hand:\n");
    ViewPlayerHand(player, handSize, isPlayer);
    CalculateHandValue(player, handSize, handValue, isPlayer);
    printf("$ ------- Choose your next move: ------ $\n");
    printf("$ 1 - Stop\n");
    printf("$ 2 - Draw card\n");
    printf("$ ");
    return;
}

void PrintHouse(struct Card_t ** house, int handSize, int * handValue){
    printf("$ ------------ House Hand ------------ $\n");
    return;
}
