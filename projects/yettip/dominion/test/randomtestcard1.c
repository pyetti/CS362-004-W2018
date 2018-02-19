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

void testAdventurer();

static const int run(void) {
	srand(time(NULL));
	testAdventurer();
	return 9;
}

void testAdventurer() {
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, baron, sea_hag, tribute, smithy};
	struct gameState state;
	for (int test = 0; test < 1000; ++test) {
		int numOfPlayers = getRandomNumberOfPlayers(4, 2);
		initializeGame(numOfPlayers, k, 2, &state);
		int player = getRandomPlayer(numOfPlayers);
		state.whoseTurn = player;
		int coinsBefore = cardCountInHand(player, copper, state) + cardCountInHand(player, silver, state) + cardCountInHand(player, gold, state);
		adventurerCard(player, &state);
		int coinsAfter = cardCountInHand(player, copper, state) + cardCountInHand(player, silver, state) + cardCountInHand(player, gold, state);
		printf("TEST ADVENTURER CARD: coins before = %d, coins after = %d | ", coinsBefore, coinsAfter);
		assertA_GreaterThan_B((void*) coinsAfter, (void*) coinsBefore + 1, "");
	}
	printf("\nDONE");
}

const struct unittest_vtable_ randomtestcard1[] = {{run}};
