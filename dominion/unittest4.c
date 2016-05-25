#include "dominion.h"
#include <stdio.h>

int failed = 0;

void myassert(int b,char* msg) {
  if (b == 0) {
    printf("FAILED ASSERTION: %s\n",msg);
    failed = 1;
  }
}

void checkasserts() {
  if (!failed) {
    printf ("TEST SUCCESSFULLY COMPLETED.\n");
  }
}

int main() {
  struct gameState g;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,
	       outpost,baron,tribute};

   initializeGame(2, k, 5, &g);
   int r = shuffle(2, &g);
   myassert(r == -1, "Initialized with 2 players and asked to shuffle the 2nd player, should pass");

  checkasserts();
  return 0;
}
