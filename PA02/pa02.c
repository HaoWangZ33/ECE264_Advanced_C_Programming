// ECE 264 Purdue University
// Spring 2016
// You may modify this file for testing but this file
// will not be submitted.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "utility.h"
#include "answer02.h"
int main(int argc, char ** argv)
{
  char deck[MAX_SIZE] = {'A', '2', '3', '4', 
			 '5', '6', '7', '8'};

  CardDeck origdeck;
  bcopy(deck, origdeck.cards, MAX_SIZE * sizeof(char));
  origdeck.size = 4;
  repeatShuffle(origdeck, 3);
  return EXIT_SUCCESS;
}

