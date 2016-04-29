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
  int r = smithyEffect(&g, 0, 0); // returns 0 if pass

  int s = cardEffect("smithy", 0, 0, 0, &g, 0, 0 ); // returns 0 if pass

  int result = r == 0 || s == 0; // if either pass, return 1
  myassert(result == 1, "Testing Smithy card, should pass");

  checkasserts();
  return 0;
}
