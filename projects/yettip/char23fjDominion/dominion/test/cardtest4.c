/************************************************************************
Author: Peter Yetti 
Date:  1/28/18
Description: Implementation for cardtest4.c
*************************************************************************/

#include <stdio.h>
#include "../dominion.h"
#include "../dominion_helpers.h"
#import "unittest.h"
#include "assert.h"

void test_minion_card_choice_1(struct gameState state);
void test_minion_card_choice_2_other_player_does_not_discards(struct gameState state);
void test_minion_card_choice_2_other_player_discards(struct gameState state);

static const int run(void) {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 2, &G);
	test_minion_card_choice_1(G);

	initializeGame(2, k, 2, &G);
	test_minion_card_choice_2_other_player_does_not_discards(G);

	initializeGame(2, k, 2, &G);
	test_minion_card_choice_2_other_player_discards(G);
	return 4;
}

void test_minion_card_choice_1(struct gameState state) {
	int coins = state.coins, playedCardCount = state.playedCardCount;
	cardEffect(minion, 1, 0, 0, &state, 0, 0);
	assertA_Equals_B((void *)coins + 2, (void *)state.coins, "Increase coins by 2 from cardEffect(minion), choice 1");
	assertA_Equals_B((void *)minion, (void *)state.playedCards[playedCardCount], "Last played card is Minion from cardEffect(minion), choice 1");
	printf("\n");
}

void test_minion_card_choice_2_other_player_does_not_discards(struct gameState state) {
	cardEffect(minion, 0, 1, 0, &state, 0, 0);
	assertA_Equals_B((void *)4, (void *)state.handCount[state.whoseTurn], "Player has 4 cards in hand from cardEffect(minion), choice 2");
	printf("\n");
}

void test_minion_card_choice_2_other_player_discards(struct gameState state) {
	int whoseTurn = state.whoseTurn;
	state.handCount[whoseTurn + 1] = 5;

	int i;
	for (i = 0; i < 10; i++) {
		state.hand[whoseTurn + 1][i] = salvager;
	}

	cardEffect(minion, 0, 1, 0, &state, 0, 0);
	assertA_Equals_B((void *)4, (void *)state.handCount[whoseTurn], "Player has 4 cards in hand from cardEffect(minion), choice 2");
	assertA_Equals_B((void *)4, (void *)state.handCount[whoseTurn + 1], "Other player has 4 cards in hand from cardEffect(minion), choice 2");
	printf("\n");
}

const struct unittest_vtable_ card_unittest4[] = {{run}};