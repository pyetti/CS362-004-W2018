/************************************************************************
Author: Peter Yetti 
Date:  1/23/18
Description: Implementation for unittest3.c
*************************************************************************/

#include "../dominion.h"
#import "unittest.h"
#include "assert.h"

void test_game_over_true_no_province_cards(struct gameState *gameState);
void test_game_over_true_three_supply_pile_at_0(struct gameState *gameState);
void test_game_over_false(struct gameState *gameState);

static const int run(void) {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	initializeGame(2, k, 2, &G);
	test_game_over_true_no_province_cards(&G);

	initializeGame(2, k, 2, &G);
	test_game_over_true_three_supply_pile_at_0(&G);

	initializeGame(2, k, 2, &G);
	test_game_over_false(&G);
	return 0;
}

void test_game_over_true_no_province_cards(struct gameState *gameState) {
	gameState->supplyCount[province] = 0;
	assertTrue(isGameOver(gameState), "test_game_over_true_no_province_cards");
}

void test_game_over_true_three_supply_pile_at_0(struct gameState *gameState) {
	gameState->supplyCount[smithy] = 0;
	gameState->supplyCount[adventurer] = 0;
	gameState->supplyCount[salvager] = 0;
	assertTrue(isGameOver(gameState), "test_game_over_true_three_supply_pile_at_0");
}

void test_game_over_false(struct gameState *gameState) {
	gameState->supplyCount[smithy] = 0;
	gameState->supplyCount[adventurer] = 0;
	gameState->supplyCount[province] = 1;
	assertTrue(!isGameOver(gameState), "test_game_over_false");
}

const struct unittest_vtable_ unittest3[] = {{run}};