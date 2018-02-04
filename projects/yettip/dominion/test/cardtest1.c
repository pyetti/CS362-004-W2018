/************************************************************************
Author: Peter Yetti 
Date:  1/28/18
Description: Implementation for cardtest1.c
*************************************************************************/

#include "../dominion.h"
#import "unittest.h"
#include "assert.h"

void test_smithy_card(struct gameState gameState);

static const int run(void) {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 2, &G);
	test_smithy_card(G);
	return 4;
}

void test_smithy_card(struct gameState gameState) {
	playCard(smithy, -1, -1, -1, &gameState);
}

const struct unittest_vtable_ card_unittest1[] = {{run}};