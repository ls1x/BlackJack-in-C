#include <stdio.h>
#include <unistd.h>
#include "../include/deck.h"
#include "../include/player.h"
#include "../include/view.h"
#include "../include/rules.h"

int main(){
    int deckSize = DECK_SIZE;
    int playerHandSize = PLAYER_STARTING_HAND;
    int playerHandValue[] = {0,0};
    int houseHandSize = PLAYER_STARTING_HAND;
    int houseHandValue[] = {0,0};
    char cardTitle[] = {'2','3','4','5','6','7','8','9','X','J','Q','K','A'};
    char * cardSuit[]  = {"♠", "♥", "♦", "♣"};
    // Allocate Deck of Cards
    struct Card_t ** deck = calloc(DECK_SIZE, sizeof(struct Card_t *));
    if (deck == NULL){
        perror("[ERR-Calloc]");
        return -1;
    }
    // Allocate Player
    struct Card_t ** player = calloc(PLAYER_STARTING_HAND, sizeof(struct Card_t *));
    if (player == NULL){
        perror("[ERR-Calloc]");
        return -1;
    }
    // Allocate House
    struct Card_t ** house = calloc(PLAYER_STARTING_HAND, sizeof(struct Card_t *));
    if (house == NULL){
        perror("[ERR-Calloc]");
        return -1;
    }
    // Preparation phase:
    AllocateDeck(deck);  
    GenerateDeck(deck, cardTitle, cardSuit);
    RandomizeDeck(deck, deckSize);
    // Generate Player
    AllocatePlayer(player);
    DrawFirstHand(deck, player, &deckSize);
    // Generate House
    AllocatePlayer(house);
    DrawFirstHand(deck, house, &deckSize);

    // Main loop:
    void MainLoop(){
        printf("\n");
        int playerChoice = 0; 
        while (playerChoice != 1){
            PrintView(player, playerHandSize, playerHandValue);
            if ((CheckLoseCondition(playerHandValue) == true)){
                printf("------------ You Lost!! ------------- $\n");
                break; 
            }
            // Char to int
            playerChoice = fgetc(stdin) - '0';
            if (errno != 0){
                playerChoice = 0;
            }
            if (playerChoice == 1){
                printf("$ ------- The house is playing: ------- $\n");
                ViewPlayerHand(house, houseHandSize, false);
                sleep(2);
                bool houseAI = 0;
                while(true){
                    CalculateHandValue(house, houseHandSize, houseHandValue, DEBUG);
                    houseAI = AI(houseHandValue);
                    if (houseAI == false){
                        printf("$ --------- The house stopped --------- $\n");
                        break;
                    } else {
                        printf("[$] The house drew a card.\n");
                        DrawCard(deck, &house, &deckSize, &houseHandSize);
                        ViewPlayerHand(house, houseHandSize, false);
                        sleep(2);
                    }
                }
                int result = CheckWhoWon(playerHandValue, houseHandValue);
                if (result == 1){
                    printf("$ ------------- You Won!! ------------- $\n");
                    printf("[+] House hand:\n");
                    ViewPlayerHand(house, houseHandSize, true);
                    CalculateHandValue(house, houseHandSize, houseHandValue, true);
                } else if (result == 2){
                    printf("$ ---------- The house won!! ---------- $\n");
                    printf("[+] House hand:\n");
                    ViewPlayerHand(house, houseHandSize, true);
                    CalculateHandValue(house, houseHandSize, houseHandValue, true);
                } else {
                    printf("$ -------------- Draw!! --------------- $\n");
                    printf("[+] House hand:\n");
                    ViewPlayerHand(house, houseHandSize, true);
                    CalculateHandValue(house, houseHandSize, houseHandValue, true);
                }
                break;
            } else if (playerChoice == 2){
                DrawCard(deck, &player, &deckSize, &playerHandSize);
                PrintView(player, playerHandSize, playerHandValue);
            } else {
                PrintView(player, playerHandSize, playerHandValue);
            }
        }
    }
    MainLoop();
   
    // Cleanup
    DeleteDeck(deck, deckSize);
    DeletePlayer(player, playerHandSize);
    DeletePlayer(house, houseHandSize);
    return 0;
}
