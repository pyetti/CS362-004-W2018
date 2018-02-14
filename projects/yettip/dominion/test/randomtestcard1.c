/************************************************************************
Author: Peter Yetti 
Date:  2/13/18
Description: Implementation for randomTester.c
*************************************************************************/

#include <stdlib.h>
#include "../dominion.h"
#include "../dominion_helpers.h"
#include "unittest.h"
#include "assert.h"

void testAdventurer(int numberOfCards, int numberOfPlayers);

static const int run(void) {
	testAdventurer(10, 2);
	return 9;
}

void testAdventurer(int numberOfCards, int numberOfPlayers) {
	struct gameState G;
//	int k = (int) malloc(sizeof(int) * numberOfCards);
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 2, &G);
}

const struct unittest_vtable_ randomtestcard1[] = {{run}};