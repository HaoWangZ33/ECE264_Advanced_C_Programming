#ifndef UTILITY_H
#define UTILITY_H
// do not modify this file
#define MAX_SIZE 20
typedef struct
{
  char cards[MAX_SIZE];
  int size; // actual size, must be between 0 and MAX_SIZE
  // if size < MAX_SIZE, some elements in cards are not used
} CardDeck;

// print one deck
void printDeck(CardDeck newdeck);

// print the upper and lower decks
void print2Deck(CardDeck upperdeck, CardDeck lowerdeck);

#endif 
