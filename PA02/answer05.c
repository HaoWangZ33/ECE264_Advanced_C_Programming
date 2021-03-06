#include "answer05.h"
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

// You do not have to use malloc in this exercise. If you use 
// malloc, please remember to free the memory.

void shuffling(CardDeck, int, CardDeck, int, char*, CardDeck*);

void interleave(CardDeck upperdeck, CardDeck lowerdeck)
{
   CardDeck* newdeck = malloc(sizeof(*newdeck));
   int sizeu = upperdeck.size;
   int sizel = lowerdeck.size;
   char* result = &(newdeck -> cards[0]);
   newdeck -> size = sizeu + sizel;
   shuffling(upperdeck, sizeu, lowerdeck, sizel, result, newdeck);
   free(newdeck);
}

void shuffling(CardDeck upperdeck, int sizeu, CardDeck lowerdeck, int sizel, char* result, CardDeck* newdeck)
{
   int i;
   if (sizeu == 0){
      for (i = (lowerdeck.size - sizel); i < lowerdeck.size; i++){
         *result = lowerdeck.cards[i];
         result = result + 1;
      }
      printDeck(*newdeck);
      printf("\n");
      return;
   }else if (sizel == 0){
      for (i = (upperdeck.size - sizeu); i < upperdeck.size; i++){
         *result = upperdeck.cards[i];
         result = result + 1;
      }
      printDeck(*newdeck);
      printf("\n");
      return;
   }
   //put 1 lower then re
   int indexl = lowerdeck.size - sizel;
   *result = lowerdeck.cards[indexl];
   shuffling(upperdeck, sizeu, lowerdeck, (sizel - 1), (result + 1), newdeck);
   //put 1 upper then re
   int indexu = upperdeck.size - sizeu;
   *result = upperdeck.cards[indexu];
   shuffling(upperdeck, (sizeu - 1), lowerdeck, sizel, (result + 1), newdeck);
}
