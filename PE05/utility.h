#ifndef UTILITY_H
#define UTILITY_H
// do not modify this file
#define MAX_SIZE 13
// You may use MAX_SIZE as the maximum possible size of
// the original deck
//
// You MUST NOT use 13. It is possible that MAX_SIZE is
// greater than 13 when your program is graded.
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
