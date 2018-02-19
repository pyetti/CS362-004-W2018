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

void testSmithy();

static const int run(void) {
	srand(time(NULL));
	testSmithy();
	return 2;
}

void testSmithy() {
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, baron, sea_hag, tribute, smithy};
	struct gameState state;
	for (int test = 0; test < 20; ++test) {
		int numOfPlayers = getRandomNumberOfPlayers(4, 2);
		initializeGame(numOfPlayers, k, 2, &state);
		int player = getRandomPlayer(numOfPlayers);
		state.whoseTurn = player;
		int cardsInHand = numHandCards(&state);
		int handPos = rand() % (numOfPlayers);
		smithyCard(player, handPos, &state);
		int cardsInHandNow = numHandCards(&state);
		printf("TEST SMITHY CARD: coins before = %d, coins after = %d | ", cardsInHand, cardsInHandNow);
		assertA_Equals_B((void *) cardsInHand + 3, (void *) numHandCards(&state), "");
	}
}

const struct unittest_vtable_ randomtestcard2[] = {{run}};