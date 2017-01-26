#include "answer05.h"
#include <strings.h>
#include <stdio.h>

// You do not have to use malloc in this exercise. If you use 
// malloc, please remember to free the memory.

// Hint: create a helper function for recursion
/*
  The helper function has the following flow:

  1. check the terminating conditions
     This occurs when
        a. the upper deck has no card or
	b. the lower deck has no card

     When either of the terminating conditions is met, put the
     remaining cards in the other deck to the result.  print the
     result by calling printDeck (implemented in utility.c)

     This should be the only place where printDeck is called

  2. If the terminating conditions are not met, this helper 
     function considers the two possible ways to create the 
     new deck:

        a. pick one card from the upper deck and add it to the
           new deck
            
           call the helper function again (recursion) but the
	   upper deck has one fewer card now; the lower deck
           is unchanged

        b. pick one card from the lower deck and add it to the
           new deck
            
           call the helper function again (recursion) but the
	   lower deck has one fewer card now; the upper deck
           is unchanged

   To make this helper function work, the helper function needs the
   following information as arguments:
   
   Obviously, this helper function needs information about the upper
   and the lower decks. It also needs to know how many cards are left
   in the upper and the lower decks because this information is used
   for the terminating conditions.
   
   The helper function may need additional arguments based on your
   design.

 */


void interleave(CardDeck upperdeck, 
		CardDeck lowerdeck)
{
  // create a new deck storing the result
  // this new deck's size should be the sum of the
  // sizes of upperdeck and lowerdeck
  

 
  // call the helper function with appropriate arguments




  
}

