/************************************************************************
Author: Peter Yetti 
Date:  1/28/18
Description: Implementation for cardtest3.c
*************************************************************************/

#include <stdio.h>
#include "../dominion.h"
#include "../dominion_helpers.h"
#import "unittest.h"
#include "assert.h"

void test_baron_card_choice_0(struct gameState gameState);
void test_baron_card_choice_1(struct gameState gameState);
int getNumberOfCardInHand(int card, struct gameState gameState);

static const int run(void) {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 2, &G);
	test_baron_card_choice_0(G);

	initializeGame(2, k, 2, &G);
	test_baron_card_choice_1(G);
	return 3;
}

void test_baron_card_choice_0(struct gameState gameState) {
	int whoseTurn = gameState.whoseTurn;
	int discardCount = gameState.discardCount[gameState.whoseTurn];
	cardEffect(baron, 0, 0, 0, &gameState, 0, 0);
	assertA_Equals_B((void *)6, (void *)gameState.supplyCount[estate], "Estate supply count from cardEffect(baron), choice 0");
	assertA_Equals_B((void *)5, (void *)gameState.deckCount[whoseTurn], "Deck count from cardEffect(baron), choice 0");

	int card = gameState.discard[whoseTurn][discardCount];

	assertA_Equals_B((void *)estate, (void *)card, "Estate is discarded from cardEffect(baron), choice 0");
	assertA_Equals_B((void *)discardCount + 1, (void *)gameState.discardCount[gameState.whoseTurn], "Discard count is reduced by 1 from cardEffect(baron), choice 0");
	printf("\n");
}

void test_baron_card_choice_1(struct gameState gameState) {
	int currentCoins = gameState.coins;

	gameState.hand[gameState.whoseTurn][0] = estate;
	int numberOfEstateCardsInHand = getNumberOfCardInHand(estate, gameState);

	cardEffect(baron, 1, 0, 0, &gameState, 0, 0);
	assertA_Equals_B((void *)currentCoins + 4, (void *)gameState.coins, "Increase Coins by 4 from cardEffect(baron), choice 1");
	assertA_Equals_B((void *)numberOfEstateCardsInHand - 1, (void *)getNumberOfCardInHand(estate, gameState), "Deck count from cardEffect(baron), choice 1");
	printf("\n");
}

int getNumberOfCardInHand(int card, struct gameState gameState) {
	int numberOfEstateCardsInHand = 0, i;
	for (i = 0; i < MAX_HAND; i++) {
		if (gameState.hand[gameState.whoseTurn][i] == card) numberOfEstateCardsInHand++;
	}
	return numberOfEstateCardsInHand;
}

const struct unittest_vtable_ card_unittest3[] = {{run}};