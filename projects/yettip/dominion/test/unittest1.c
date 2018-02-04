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

	assertA_Equals_B(10, G.supplyCount[curse], "test_two_player_game_initial_state: G.supplyCount[curse] = 10");
	assertA_Equals_B(8, G.supplyCount[estate], "test_two_player_game_initial_state: G.supplyCount[estate] = 8");
	assertA_Equals_B(8, G.supplyCount[duchy], "test_two_player_game_initial_state: G.supplyCount[duchy] = 8");
	assertA_Equals_B(8, G.supplyCount[province], "test_two_player_game_initial_state: G.supplyCount[province] = 8");
	assertA_Equals_B(46, G.supplyCount[copper], "test_two_player_game_initial_state: G.supplyCount[copper] = 46");
	assertA_Equals_B(40, G.supplyCount[silver], "test_two_player_game_initial_state: G.supplyCount[silver] = 40");
	assertA_Equals_B(30, G.supplyCount[gold], "test_two_player_game_initial_state: G.supplyCount[gold] = 30");
	printf("\n");
}

void test_three_player_game_initial_state() {
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(3, k, 2, &G);

	assertA_Equals_B(20, G.supplyCount[curse], "test_three_player_game_initial_state: G.supplyCount[curse] = 20");
	assertA_Equals_B(12, G.supplyCount[estate], "test_three_player_game_initial_state: G.supplyCount[estate] = 12");
	assertA_Equals_B(12, G.supplyCount[duchy], "test_three_player_game_initial_state: G.supplyCount[duchy] = 12");
	assertA_Equals_B(12, G.supplyCount[province], "test_three_player_game_initial_state: G.supplyCount[province] = 12");
	assertA_Equals_B(39, G.supplyCount[copper], "test_three_player_game_initial_state: G.supplyCount[copper] = 39");
	assertA_Equals_B(40, G.supplyCount[silver], "test_three_player_game_initial_state: G.supplyCount[silver] = 40");
	assertA_Equals_B(30, G.supplyCount[gold], "test_three_player_game_initial_state: G.supplyCount[gold] = 30");
	printf("\n");
}


const struct unittest_vtable_ unittest1[] = { { run } };
