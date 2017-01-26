// ECE 264 Purdue University
// Spring 2016
// You may modify this file for testing but this file
// will not be submitted.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "utility.h"
#include "answer06.h"
int main(int argc, char ** argv)
{
  char deck[MAX_SIZE] = {'A', '2', '3', '4', 
			 '5', '6', '7', '8', 
			 '9', 'T', 'J', 'Q', 
			 'K'};

  CardDeck origdeck;
  bcopy(deck, origdeck.cards, MAX_SIZE * sizeof(char));
  origdeck.size = MAX_SIZE;
  int size; // change the size to test the program
  // if it is smaller than MAX_SIZE, some cards are not used
  // the original deck has at least two cards
  for (size = 2; size <= 5; size ++)
    {
      printf("\n\n*** size = %d***\n", size);
      origdeck.size = size; 
      shuffle(origdeck);
    }
  return EXIT_SUCCESS;
}

