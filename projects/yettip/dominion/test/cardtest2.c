/************************************************************************
Author: Peter Yetti 
Date:  1/28/18
Description: Implementation for cardtest2.c
*************************************************************************/

#include <stdio.h>
#include "../dominion.h"
#include "../dominion_helpers.h"
#import "unittest.h"
#include "assert.h"

void test_adventurer_card(struct gameState gameState);

static const int run(void) {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 2, &G);
	test_adventurer_card(G);
	return 2;
}

void test_adventurer_card(struct gameState gameState) {
	int whoseTurn = gameState.whoseTurn;
	cardEffect(adventurer, 0, 0, 0, &gameState, 0, 0);
	assertA_Equals_B(7, gameState.handCount[whoseTurn], "Hand count from cardEffect(adventurer)");
	assertA_Equals_B(3, gameState.deckCount[whoseTurn], "Deck count from cardEffect(adventurer)");
	printf("\n");
}

const struct unittest_vtable_ card_unittest2[] = {{run}};
