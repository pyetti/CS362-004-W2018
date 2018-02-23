CFLAGS = -Wall -fpic -coverage -lm -std=c99
NOWARNINGS = -w -fpic -coverage -lm -std=c99

cardTestFiles = test/cardtest1.c test/cardtest2.c test/cardtest3.c test/cardtest4.c
unitTestFiles = test/unittest.h test/unittest1.c test/unittest2.c test/unittest3.c test/unittest4.c
cardTestFilesOFiles = cardtest1.o cardtest2.o cardtest3.o cardtest4.o
unitTestFilesOFiles = unittest1.o unittest2.o unittest3.o unittest4.o

randomTestFiles = test/randomtestcard1.c test/randomtestcard2.c test/randomtestcard3.c
randomTestFilesOFiles = randomtestcard1.o randomtestcard2.o randomtestcard3.o
testUtilityFiles = test/TestUtility.c
testUtilityFilesOFiles = TestUtility.o

cards.o: cards.h cards.c
	gcc -c dominion.c cards.c -g $(NOWARNINGS)

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(NOWARNINGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c  -g  $(NOWARNINGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to enter: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

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

compileUnitTests: $(cardTestFiles) $(unitTestFiles) test/assert.h test/assert.c
	gcc -c $(cardTestFiles) $(unitTestFiles) test/assert.c $(NOWARNINGS)

testRunner: dominion.o cards.o test/testRunner.c compileUnitTests
	gcc -o testRunner test/testRunner.c $(cardTestFilesOFiles) $(unitTestFilesOFiles) assert.o cards.o dominion.o rngs.o -fpic -coverage -lm -w

unittestresults.out: testRunner
	./testRunner &> unittestresult.out
	gcov -abcfu dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

compileRandomTests: $(randomTestFiles) $(testUtilityFiles) test/assert.h test/assert.c
	gcc -c $(randomTestFiles) $(testUtilityFiles) test/assert.c $(NOWARNINGS)

randomTestRunner: dominion.o cards.o test/testRunner.c compileRandomTests
	gcc -o randomTestRunner test/randomTestRunner.c $(randomTestFilesOFiles) $(testUtilityFilesOFiles) assert.o cards.o dominion.o rngs.o -fpic -coverage -lm -w

randomtestresults.out: randomTestRunner
	./randomTestRunner &> randomtestresults.out
	gcov -abcfu cards.c >> randomtestresults.out
	cat cards.c.gcov >> randomtestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe testRunner randomTestRunner test/unittest.h.gch
