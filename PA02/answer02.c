#include "answer02.h"
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
void divideDeck(CardDeck origdeck, CardDeck * upperdeck, CardDeck * lowerdeck);
void interleave(CardDeck upperdeck, CardDeck lowerdeck, int k);
void shuffling(CardDeck, int, CardDeck, int, char*, CardDeck*, int);

void repeatShuffle(CardDeck origdeck, int k)
{
  if (k <= 0){
    printDeck(origdeck);
  }
  else{
    int numpairs = (origdeck.size) - 1; //calculate the number of upper-low deck pairs
    CardDeck * upperdeck = NULL;
    CardDeck * lowerdeck = NULL;
    upperdeck = malloc(sizeof(*upperdeck) * numpairs); // allocate memory
    lowerdeck = malloc(sizeof(*lowerdeck) * numpairs); // allocate memory
    if (upperdeck == NULL)
      {  free(lowerdeck);
         return;}
    if (lowerdeck == NULL)
      {  free(upperdeck);
         return;}
    divideDeck(origdeck, upperdeck, lowerdeck); // call divideDeck to fill upperdeck and lowerdeck 
    while (numpairs > 0)
    {
      interleave(upperdeck[numpairs - 1], lowerdeck[numpairs - 1], k); // for each pairs call interleave
      numpairs = numpairs - 1;
    }
    free(upperdeck);
    free(lowerdeck);
  }

  //       for each pair of upper and lower decks, interleave the cards,
  //           when the interleaving is complete, have to perform another 
  //           k-1 rounds of shuffling with the new deck
  //
}

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

void interleave(CardDeck upperdeck, CardDeck lowerdeck, int k)
{
   CardDeck* newdeck = malloc(sizeof(*newdeck));
   int sizeu = upperdeck.size;
   int sizel = lowerdeck.size;
   char* result = &(newdeck -> cards[0]);
   newdeck -> size = sizeu + sizel;
   shuffling(upperdeck, sizeu, lowerdeck, sizel, result, newdeck, k);
   free(newdeck);
}

void shuffling(CardDeck upperdeck, int sizeu, CardDeck lowerdeck, int sizel, char* result, CardDeck* newdeck, int k)
{
   int i;
   if (sizeu == 0){
      for (i = (lowerdeck.size - sizel); i < lowerdeck.size; i++){
         *result = lowerdeck.cards[i];
         result = result + 1;
      }
      repeatShuffle(*newdeck, k-1);
      return;
   }else if (sizel == 0){
      for (i = (upperdeck.size - sizeu); i < upperdeck.size; i++){
         *result = upperdeck.cards[i];
         result = result + 1;
      }
      repeatShuffle(*newdeck, k-1);
      return;
   }
   int indexl = lowerdeck.size - sizel;  //put 1 lower then re
   *result = lowerdeck.cards[indexl];
   shuffling(upperdeck, sizeu, lowerdeck, (sizel - 1), (result + 1), newdeck, k);
   int indexu = upperdeck.size - sizeu;  //put 1 upper then re
   *result = upperdeck.cards[indexu];
   shuffling(upperdeck, (sizeu - 1), lowerdeck, sizel, (result + 1), newdeck, k);
}
