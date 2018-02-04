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
	assertA_Equals_B(0, (void *)getCost(curse), "test_get_card_cost:CURSE");
	assertA_Equals_B((void *)2, (void *)getCost(estate), "test_get_card_cost:ESTATE");
	assertA_Equals_B((void *)5, (void *)getCost(duchy), "test_get_card_cost:DUCHY");
	assertA_Equals_B((void *)8, (void *)getCost(province), "test_get_card_cost:PROVINCE");
	assertA_Equals_B(0, (void *)getCost(copper), "test_get_card_cost:COPPER");
	assertA_Equals_B((void *)3, (void *)getCost(silver), "test_get_card_cost:SILVER");
	assertA_Equals_B((void *)6, (void *)getCost(gold), "test_get_card_cost:GOLD");
	assertA_Equals_B((void *)6, (void *)getCost(adventurer), "test_get_card_cost:ADVENTURER");
}

const struct unittest_vtable_ unittest4[] = {{run}};