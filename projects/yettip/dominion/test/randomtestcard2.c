/************************************************************************
Author: Peter Yetti 
Date:  2/13/18
Description: Implementation for randomtestcard2.c
*************************************************************************/

#include <stdio.h>
#include "../dominion.h"
#include "unittest.h"
#include "assert.h"
#include "../cards.h"

void testSmithy(int count);

static const int run(void) {
	srand(time(NULL));
	testSmithy(testCount);
	return 2;
}

void testSmithy(int count) {
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, baron, sea_hag, tribute, smithy};
	struct gameState state;
	for (int test = 0; test < count; ++test) {
		int numOfPlayers = getRandomNumberOfPlayers(4, 2);
		initializeGame(numOfPlayers, k, 2, &state);
		int player = getRandomPlayer(numOfPlayers);
		state.whoseTurn = player;
		int cardsInHand = numHandCards(&state);
		int handPos = rand() % (numOfPlayers);
		smithyCard(player, handPos, &state);
		int cardsInHandNow = numHandCards(&state);
		char testResult[1000];
		sprintf(testResult, "TEST SMITHY CARD: coins before = %d, coins after = %d", cardsInHand, cardsInHandNow);
		assertA_Equals_B((void *) cardsInHand + 3, (void *) numHandCards(&state), testResult);
	}
	printf("SMITHY CARD TEST COMPLETE. %d tests run\n\n", testCount);
}

const struct unittest_vtable_ randomtestcard2[] = {{run}};