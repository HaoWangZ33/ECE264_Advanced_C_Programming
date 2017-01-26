// do not modify this file
#include "utility.h"
#include <stdio.h>

void printDeck(CardDeck deck)
{
  printf("[");
  int iter;
  for (iter = 0; iter < deck.size; iter ++)
    {
      printf("%c",  deck.cards[iter]);
    }
  printf("]");
}

void print2Deck(CardDeck upperdeck, CardDeck lowerdeck)
{
  printf("upper deck:");
  printDeck(upperdeck);
  printf(" === lower deck: ");
  printDeck(lowerdeck);
  printf("\n");
}
