CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unittest1: unittest1.c dominion.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

unittest2: unittest2.c dominion.o
	gcc -o unittest2 unittest2.c -g  dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

unittest3: unittest3.c dominion.o
	gcc -o unittest3 unittest3.c -g  dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

unittest4: unittest4.c dominion.o
	gcc -o unittest4 unittest4.c -g  dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

cardtest1: cardtest1.c dominion.o
	gcc -o cardtest1 cardtest1.c -g  dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

cardtest2: cardtest2.c dominion.o
	gcc -o cardtest2 cardtest2.c -g  dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

cardtest3: cardtest3.c dominion.o
	gcc -o cardtest3 cardtest3.c -g  dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

cardtest4: cardtest4.c dominion.o
	gcc -o cardtest4 cardtest4.c -g  dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	unittest1 > unittestresults.out
	gcov unittest1.c >> unittestresults.out
	unittest2 >> unittestresults.out
	gcov unittest2.c >> unittestresults.out
	unittest3 >> unittestresults.out
	gcov unittest3.c >> unittestresults.out
	unittest4 >> unittestresults.out
	gcov unittest4.c >> unittestresults.out
	cardtest1 >> unittestresults.out
	gcov cardtest1.c >> unittestresults.out
	cardtest2 >> unittestresults.out
	gcov cardtest2.c >> unittestresults.out
	cardtest3 >> unittestresults.out
	gcov cardtest3.c >> unittestresults.out
	cardtest4 >> unittestresults.out
	gcov cardtest4.c >> unittestresults.out

randomtestadventurer.out: randomtestadventurer
	randomtestadventurer > randomtestadventurer.out
	gcov randomtestadventurer.c  >> randomtestadventurer.out
randomtestcard1.out: randomtestcard1
	randomtestcard1 > randomtestcard1.out
	gcov randomtestcard1.c  >> randomtestcard1.out
randomtestcard2.out: randomtestcard2
	randomtestcard2 > randomtestcard2.out
	gcov randomtestcard2.c  >> randomtestcard2.out

randomtest: randomtestadventurer.out randomtestcard1.out randomtestcard2.out

randomtestadventurer: randomtestadventurer.c dominion.o
	gcc -o randomtestadventurer randomtestadventurer.c -g  dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

randomtestcard1: randomtestcard1.c dominion.o
	gcc -o randomtestcard1 randomtestcard1.c -g  dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

randomtestcard2: randomtestcard1.c dominion.o
	gcc -o randomtestcard2 randomtestcard2.c -g  dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm

testdominion: dominion.o testdominion.c
	gcc -o testdominion testdominion.c -g dominion.o rngs.o interface.o -fprofile-arcs -ftest-coverage -Wall -fpic -coverage -lm;
	./testdominion 42 > testdominion.out;
	gcov dominion.c >> testdominion.out;

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out randomtestadventurer randomtestcard1 randomtestcard2 randomtest testdominion

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a .DS_Store
	rm -rf *.dSYM
