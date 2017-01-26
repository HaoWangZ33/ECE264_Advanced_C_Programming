// ECE 264 Purdue University
// Spring 2016
// You may modify this file for testing but this file
// will not be submitted.
//
// You are strongly encouraged to create more test cases.
//
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "utility.h"
#include "answer05.h"
int main(int argc, char ** argv)
{
  char deck[MAX_SIZE] = {'A', '2', '3', '4', 
			 '5', '6', '7', '8', 
			 '9', 'T', 'J', 'Q', 
			 'K'};

  CardDeck upperdeck;
  CardDeck lowerdeck;
  upperdeck.size = 3;
  lowerdeck.size = 4;
  bcopy(deck, upperdeck.cards, 3 * sizeof(char));
  bcopy(& deck[5], lowerdeck.cards, 4 * sizeof(char));
  // print2Deck(upperdeck, lowerdeck);
  interleave(upperdeck, lowerdeck);
  return EXIT_SUCCESS;
}

