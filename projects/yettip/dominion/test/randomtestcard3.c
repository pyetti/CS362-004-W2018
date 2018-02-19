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

void testSteward();

static const int run(void) {
	srand(time(NULL));
	testSteward();
	return 3;
}

void testSteward() {
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, baron, sea_hag, tribute, smithy};
	struct gameState state;
}

const struct unittest_vtable_ randomtestcard3[] = {{run}};