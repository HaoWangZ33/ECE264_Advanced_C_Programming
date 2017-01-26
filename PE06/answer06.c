#include "answer06.h"
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
// The following line must be above divideDeck
#ifdef TEST_DIVIDE 
void divideDeck(CardDeck origdeck, CardDeck * upperdeck, CardDeck * lowerdeck)
{
  int numpairs = (origdeck.size) - 1;
  int count;
  for (count = 1; count <= numpairs; count++){
    bcopy(origdeck.cards, upperdeck[count - 1].cards, count * sizeof(char));
    upperdeck[count - 1].size = count;
    bcopy(&(origdeck.cards[count]), lowerdeck[count - 1].cards, (numpairs - count + 1) * sizeof(char));
    lowerdeck[count - 1].size = numpairs - count + 1;
  }
}
#endif
// The previous line must be below divideDeck
#ifdef TEST_INTERLEAVE
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
   int indexl = lowerdeck.size - sizel;  //put 1 lower then re
   *result = lowerdeck.cards[indexl];
   shuffling(upperdeck, sizeu, lowerdeck, (sizel - 1), (result + 1), newdeck);
   int indexu = upperdeck.size - sizeu;  //put 1 upper then re
   *result = upperdeck.cards[indexu];
   shuffling(upperdeck, (sizeu - 1), lowerdeck, sizel, (result + 1), newdeck);
}
#endif
#ifdef TEST_SHUFFLE
void shuffle(CardDeck origdeck)
{
  int numpairs = (origdeck.size) - 1; //calculate the number of upper-low deck pairs
  CardDeck * upperdeck = NULL;
  CardDeck * lowerdeck = NULL;
  upperdeck = malloc(sizeof(*upperdeck) * numpairs); // allocate memory
  lowerdeck = malloc(sizeof(*lowerdeck) * numpairs); // allocate memory
  if (upperdeck == NULL)
    {return;
    }
  if (lowerdeck == NULL)
    {return;
    }
  divideDeck(origdeck, upperdeck, lowerdeck); // call divideDeck to fill upperdeck and lowerdeck 

  while (numpairs > 0)
    {
      interleave(upperdeck[numpairs - 1], lowerdeck[numpairs - 1]); // for each pairs call interleave
      numpairs = numpairs - 1;
    }
  free(upperdeck);
  free(lowerdeck);
} 
#endif
