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

  int r = initializeGame(-1, k, 5, &g);
  myassert(r == -1, "-1 players inputted, should fail");

  checkasserts();
  return 0;
}
