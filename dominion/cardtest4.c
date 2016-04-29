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

  // test function
  int before = g.outpostPlayed;
  cardEffect("outpost", 0, 0, 0, &g, 0, 0 ); // returns 0 if pass
  int after = g.outpostPlayed;

  int result = after - before; // should result in 1
  myassert(result == 1, "Testing outpost card, should pass");

  checkasserts();
  return 0;
}
