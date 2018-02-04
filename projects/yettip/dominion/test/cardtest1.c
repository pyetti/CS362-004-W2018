/************************************************************************
Author: Peter Yetti 
Date:  1/28/18
Description: Implementation for cardtest1.c
*************************************************************************/

#include <stdio.h>
#include "../dominion.h"
#include "../dominion_helpers.h"
#import "unittest.h"
#include "assert.h"

void test_smithy_card(struct gameState gameState);

static const int run(void) {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 2, &G);
	test_smithy_card(G);
	return 1;
}

void test_smithy_card(struct gameState gameState) {
	int whoseTurn = gameState.whoseTurn;
	cardEffect(smithy, 1, 0, 0, &gameState, 0, 0);
	assertA_Equals_B((void *)7, (void *)gameState.handCount[whoseTurn], "Hand count from cardEffect(smithy)");
	assertA_Equals_B((void *)2, (void *)gameState.deckCount[whoseTurn], "Deck count from cardEffect(smithy)");
	printf("\n");
}

const struct unittest_vtable_ card_unittest1[] = {{run}};