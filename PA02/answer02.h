// do not modify this file
#ifndef ANSWER02_H
#define ANSWER02_H
#include "utility.h"
// given a deck of cards, generate all possible decks after shuffling k times
// Print only the results obtained after k rounds of shuffling
//
// Please remember to release (by calling free) all memory allocated by
// malloc.  You will lose points (50% points) if your program leaks
// memory. You must use valgrind to check memory leak before
// submission.
//
// Hint: it is likely that the functions used in PE05/PE06 require some
// adjustments.

void repeatShuffle (CardDeck origdeck, int k);
#endif
