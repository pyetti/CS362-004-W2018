/************************************************************************
Author: Peter Yetti 
Date:  2/25/18
Description: Implementation for seaHagCardTest.c
*************************************************************************/

#include <stdio.h>
#include "../dominion.h"
#import "unittest.h"
#include "assert.h"
#include "../cards.h"

void test_seaHag_card(struct gameState gameState);

static const int run(void) {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 2, &G);
	test_seaHag_card(G);
	return 1;
}

void test_seaHag_card(struct gameState gameState) {
	int whoseTurn = gameState.whoseTurn;
	gameState.deck[whoseTurn + 1][gameState.deckCount[whoseTurn + 1]] = smithy;

	seaHagCard(whoseTurn, &gameState);

	assertA_Equals_B((void *) curse, (void *) gameState.deck[whoseTurn + 1][gameState.deckCount[whoseTurn + 1]], "Top card is not a curse cardEffect(seaHag)");
	printf("\n");
}

const struct unittest_vtable_ seaHagCardTest[] = {{run}};