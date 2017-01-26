// do not modify this file
#ifndef ANSWER06_H
#define ANSWER06_H
#include "utility.h"
// This function divides a deck of cards to upper and lower decks. The
// first argument is the input and the other arguments are outputs.
//
// upperdeck and lowdeck are arrays of decks. Each element is 
// a deck. upperdeck[i] is the upper deck corresponding to
// lowerdeck[i]
//
// upperdeck and lowerdeck should have enough memory space to store
// correct outputs. This function should NOT allocate memory (i.e.,
// this function should not call malloc or similar functions).
//
// the memory needed for upperdeck and lowdeck should be allocated
// outside divideDeck
//
void divideDeck(CardDeck origdeck, 
		CardDeck * upperdeck, 
		CardDeck * lowerdeck);

//
// This function takes an upper deck and a lower deck
// and interleaves the cards.  
// 
// When a new order is generated, print the deck by calling
// printDeck in utility

void interleave(CardDeck upperdeck, CardDeck lowerdeck);

// given a deck of cards, generate all possible decks after
// shuffling once
// hint: call divideDeck and interleave
void shuffle (CardDeck origdeck);

#endif
