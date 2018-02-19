/************************************************************************
Author: Peter Yetti 
Date:  2/13/18
Description: Implementation for randomTester.c
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../dominion.h"
#include "unittest.h"
#include "assert.h"
#include "../cards.h"

void testAdventurer(int count);

static const int run() {
	srand(time(NULL));
	testAdventurer(testCount);
	return 9;
}

void testAdventurer(int count) {
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, baron, sea_hag, tribute, smithy};
	struct gameState state;
	for (int test = 0; test < count; ++test) {
		int numOfPlayers = getRandomNumberOfPlayers(4, 2);
		initializeGame(numOfPlayers, k, 2, &state);
		int player = getRandomPlayer(numOfPlayers);
		state.whoseTurn = player;
		int coinsBefore = cardCountInHand(player, copper, state) + cardCountInHand(player, silver, state) +
		                  cardCountInHand(player, gold, state);
		adventurerCard(player, &state);
		int coinsAfter = cardCountInHand(player, copper, state) + cardCountInHand(player, silver, state) +
		                 cardCountInHand(player, gold, state);
		char testResult[1000];
		sprintf(testResult, "TEST ADVENTURER CARD: coins before = %d, coins after = %d", coinsBefore, coinsAfter);
		assertA_GreaterThan_B((void *) coinsAfter, (void *) coinsBefore + 1, testResult);
	}
	printf("ADVENTURER CARD TEST COMPLETE. %d tests run\n\n", testCount);
}

const struct unittest_vtable_ randomtestcard1[] = {{run}};
