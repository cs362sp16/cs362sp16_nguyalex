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

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,great_hall,ambassador,
	       outpost,baron,tribute};

  initializeGame(2, k, 5, &g);

  // test coin increase
  int before = g.coins;
  cardEffect("embargo", 0, 0, 0, &g, 0, 0 ); // returns 0 if pass
  int after = g.coins;

  int result = after - before;
  myassert(result == 2, "Testing Embargo's coin increase, should pass");

  checkasserts();
  return 0;
}
