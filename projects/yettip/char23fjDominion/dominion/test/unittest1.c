/************************************************************************
Author: Peter Yetti 
Date:  1/22/18
Description: Implementation for unittest1.c
*************************************************************************/

#include <stdio.h>
#include "../dominion.h"
#import "unittest.h"
#include "assert.h"

void test_two_player_game_initial_state();
void test_three_player_game_initial_state();

static const int run(void) {
	test_two_player_game_initial_state();
	test_three_player_game_initial_state();
	return 1;
}

void test_two_player_game_initial_state() {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, 2, &G);

	assertA_Equals_B((void *)10, (void *)G.supplyCount[curse], "test_two_player_game_initial_state: G.supplyCount[curse] = 10");
	assertA_Equals_B((void *)8, (void *)G.supplyCount[estate], "test_two_player_game_initial_state: G.supplyCount[estate] = 8");
	assertA_Equals_B((void *)8, (void *)G.supplyCount[duchy], "test_two_player_game_initial_state: G.supplyCount[duchy] = 8");
	assertA_Equals_B((void *)8, (void *)G.supplyCount[province], "test_two_player_game_initial_state: G.supplyCount[province] = 8");
	assertA_Equals_B((void *)46, (void *)G.supplyCount[copper], "test_two_player_game_initial_state: G.supplyCount[copper] = 46");
	assertA_Equals_B((void *)40, (void *)G.supplyCount[silver], "test_two_player_game_initial_state: G.supplyCount[silver] = 40");
	assertA_Equals_B((void *)30, (void *)G.supplyCount[gold], "test_two_player_game_initial_state: G.supplyCount[gold] = 30");
	printf("\n");
}

void test_three_player_game_initial_state() {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(3, k, 2, &G);

	assertA_Equals_B((void *)20, (void *)G.supplyCount[curse], "test_three_player_game_initial_state: G.supplyCount[curse] = 20");
	assertA_Equals_B((void *)12, (void *)G.supplyCount[estate], "test_three_player_game_initial_state: G.supplyCount[estate] = 12");
	assertA_Equals_B((void *)12, (void *)G.supplyCount[duchy], "test_three_player_game_initial_state: G.supplyCount[duchy] = 12");
	assertA_Equals_B((void *)12, (void *)G.supplyCount[province], "test_three_player_game_initial_state: G.supplyCount[province] = 12");
	assertA_Equals_B((void *)39, (void *)G.supplyCount[copper], "test_three_player_game_initial_state: G.supplyCount[copper] = 39");
	assertA_Equals_B((void *)40, (void *)G.supplyCount[silver], "test_three_player_game_initial_state: G.supplyCount[silver] = 40");
	assertA_Equals_B((void *)30, (void *)G.supplyCount[gold], "test_three_player_game_initial_state: G.supplyCount[gold] = 30");
	printf("\n");
}


const struct unittest_vtable_ unittest1[] = { { run } };
