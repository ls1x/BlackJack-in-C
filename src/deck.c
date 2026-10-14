#include "../include/deck.h"

void GenerateDeck(struct Card_t ** deck, char * cardTitle, char ** cardSuit){
    int titleCount = 0;
    int suitCount = 0;
    for (int i = 0; i < DECK_SIZE; i++){
        if (i < 13){
            deck[i]->title = cardTitle[titleCount];
            strncpy(deck[i]->suit, cardSuit[suitCount], 4);
            titleCount++;
        } else if (i < 26){
            if (i == 13){
                titleCount = 0;
                suitCount++;
            }
            deck[i]->title = cardTitle[titleCount];
            strncpy(deck[i]->suit, cardSuit[suitCount], 4);
            titleCount++;
        } else if (i < 39){
            if (i == 26){
                titleCount = 0;
                suitCount++;
            }
            deck[i]->title = cardTitle[titleCount];
            strncpy(deck[i]->suit, cardSuit[suitCount], 4);
            titleCount++;
        } else if (i < 52){
            if (i == 39){
                titleCount = 0;
                suitCount++;
            }
            deck[i]->title = cardTitle[titleCount];
            strncpy(deck[i]->suit, cardSuit[suitCount], 4);
            titleCount++;
        }
    }
    printf("[+] Deck Generated\n");
    //deck[0]->title = cardTitle[0];
    return;
}

void ViewDeck(struct Card_t ** deck, int deckSize){
    printf("[DECK:]\n");
    for (int i = 0; i < deckSize; i++){
        printf("Card[%d] Title:%c Suit:%s\n", i, deck[i]->title, deck[i]->suit);
    }
    return;
}

void DeleteDeck(struct Card_t ** deck, int deckSize){
    for (int i = 0; i < deckSize; i++){
        free(deck[i]);
    }
    free(deck);    
    return;
}

void RandomizeDeck(struct Card_t ** deck, int deckSize){
    srand(time(NULL));
    int randomNum = 0;
    struct Card_t origCard = {0};
    struct Card_t randCard = {0};
    for (int i = 0; i < deckSize; i++){
       //strncpy(deck[i]->suit, cardSuit[suitCount], 4);
       randomNum = rand() % deckSize;
       origCard.title = deck[i]->title;
       strncpy(origCard.suit, deck[i]->suit, 4);
       randCard.title = deck[randomNum]->title;
       strncpy(randCard.suit, deck[randomNum]->suit, 4);
       deck[i]->title = randCard.title;
       strncpy(deck[i]->suit, randCard.suit, 4);
       deck[randomNum]->title = origCard.title;
       strncpy(deck[randomNum]->suit, origCard.suit, 4);
    }
    printf("[+] Deck Randomized\n");
    return;
}

int AllocateDeck(struct Card_t ** deck){
    for (int i = 0; i < DECK_SIZE; i++){
        if ((deck[i] = calloc(1,sizeof(struct Card_t))) == NULL){
            perror("[ERR-Calloc]");
            return -1; 
        }
    }
    printf("[+] Deck Allocated\n");
    return 0;
}
