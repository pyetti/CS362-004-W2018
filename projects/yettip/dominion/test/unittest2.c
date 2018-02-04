/************************************************************************
Author: Peter Yetti 
Date:  1/22/18
Description: Implementation for unittest2.c
*************************************************************************/

#include <stdio.h>
#include "../dominion.h"
#import "unittest.h"
#include "assert.h"

void test_buy_card_fails(struct gameState);
void test_buy_card_passes(struct gameState);

static const int run(void) {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 2, &G);

	test_buy_card_fails(G);
	test_buy_card_passes(G);
	return 2;
}

void test_buy_card_fails(struct gameState G) {
	G.numBuys = 0;
	printf("test_buy_card_fails: Current number of buys = %d\n", G.numBuys);
	assertA_Equals_B(-1, buyCard(province, &G), "User has no buys");

	G.numBuys = 1;
	assertA_Equals_B(-1, buyCard(province, &G), "User doesn't have enough coins");

	assertA_Equals_B(-1, buyCard(baron, &G), "No Baron Cards to buy");
	printf("\n");
}

void test_buy_card_passes(struct gameState G) {
	int currentNumberOfBuys = G.numBuys;
	int player = G.whoseTurn;
	int discardCount = G.discardCount[player];

	printf("test_buy_card_passes: Current number of buys = %d\n", G.numBuys);
	assertA_Equals_B(10, G.supplyCount[smithy], "Supply count contains 10 smithy cards");
	assertA_Equals_B(0, buyCard(smithy, &G), "Player buys smithy");
	assertA_Equals_B(9, G.supplyCount[smithy], "Player now has 9 smithy cards");
	assertA_Equals_B(currentNumberOfBuys - 1, G.numBuys, "Player has 1 less number of buys");
	assertA_Equals_B(0, G.coins, "Player now has 9 smithy cards");
	assertA_Equals_B(discardCount + 1, G.discardCount[player], "Player has 1 more card in discard deck");
	assertA_Equals_B(0, G.numBuys, "User now has 0 buys");
	printf("\n");
}

const struct unittest_vtable_ unittest2[] = { { run } };