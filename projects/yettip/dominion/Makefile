CFLAGS = -Wall -fpic -coverage -lm
NOWARNINGS = -w -fpic -coverage -lm

cards.o: cards.h cards.c
	gcc -c dominion.c cards.c -g $(NOWARNINGS)

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(NOWARNINGS)

dominion.o: dominion.h dominion.c rngs.o cards.o
	gcc -c dominion.c cards.o -g  $(NOWARNINGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o cards.o $(CFLAGS)
#To run playdom you need to enter: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o cards.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o cards.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

testRunner: dominion.o cards.o
	gcc -o testRunner test/testRunner.c test/assert.c test/unittest* test/cardtest* cards.o dominion.o rngs.o -fpic -coverage -lm -w

unittestresults.out: testRunner
	./testRunner &> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe testRunner
