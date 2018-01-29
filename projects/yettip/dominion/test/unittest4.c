/************************************************************************
Author: Peter Yetti 
Date:  1/23/18
Description: Implementation for unittest4.c
*************************************************************************/

#include "../dominion.h"
#include "../dominion_helpers.h"
#import "unittest.h"
#include "assert.h"

void test_get_card_cost();

static const int run(void) {
	test_get_card_cost();
	return 4;
}

void test_get_card_cost() {
	assertA_Equals_B(0, getCost(curse), "test_get_card_cost:CURSE");
	assertA_Equals_B(2, getCost(estate), "test_get_card_cost:ESTATE");
	assertA_Equals_B(5, getCost(duchy), "test_get_card_cost:DUCHY");
	assertA_Equals_B(8, getCost(province), "test_get_card_cost:PROVINCE");
	assertA_Equals_B(0, getCost(copper), "test_get_card_cost:COPPER");
	assertA_Equals_B(3, getCost(silver), "test_get_card_cost:SILVER");
	assertA_Equals_B(6, getCost(gold), "test_get_card_cost:GOLD");
	assertA_Equals_B(6, getCost(adventurer), "test_get_card_cost:ADVENTURER");
}

const struct unittest_vtable_ unittest4[] = {{run}};