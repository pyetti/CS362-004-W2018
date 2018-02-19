/************************************************************************
Author: Peter Yetti 
Date:  2/13/18
Description: Implementation for randomtestcard3.c
*************************************************************************/

#include <stdio.h>
#include "../dominion.h"
#include "unittest.h"
#include "assert.h"
#include "../cards.h"

void testSteward(int count);
void asserts(int choice1, int coinsBefore, int cardsInHandBefore, struct gameState state);

static const int run(void) {
	srand(time(NULL));
	testSteward(testCount);
	return 3;
}

void testSteward(int count) {
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, baron, sea_hag, tribute, smithy};
	struct gameState state;
	for (int test = 0; test < count; ++test) {
		int numOfPlayers = getRandomNumberOfPlayers(4, 2);
		initializeGame(numOfPlayers, k, 2, &state);
		int player = getRandomPlayer(numOfPlayers);
		state.whoseTurn = player;
		int choice1 = getRandomChoice(3, 1);
		int handPos = rand() % (numOfPlayers);
		int coinsBefore = state.coins;
		int cardsInHand = numHandCards(&state);
		stewardCard(player, handPos, choice1, 0, 0, &state);
		asserts(choice1, coinsBefore, cardsInHand, state);
	}
	printf("STEWARD CARD TEST COMPLETE. %d tests run\n\n", testCount);
}

void asserts(int choice1, int coinsBefore, int cardsInHandBefore, struct gameState state) {
	if (choice1 == 1) {
		//+2 cards (-1 because of discard
		assertA_Equals_B((void *) cardsInHandBefore + 1, (void *) numHandCards(&state), "Test Steward Card: +2 Cards");
	} else if (choice1 == 2) {
		//+2 coins
		assertA_Equals_B((void *) coinsBefore + 2, (void *) state.coins, "Test Steward Card: +2 Coins");
	} else {
		//trash 2 cards in hand (-1 because of discard)
		assertA_Equals_B((void *) cardsInHandBefore -3, (void *) numHandCards(&state), "Test Steward Card: -2 Cards");
	}
}

const struct unittest_vtable_ randomtestcard3[] = {{run}};