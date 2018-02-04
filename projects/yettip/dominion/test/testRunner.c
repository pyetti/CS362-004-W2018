/************************************************************************
Author: Peter Yetti 
Date:  1/22/18
Description: Implementation for testRunner.c
*************************************************************************/

#include "unittest.h"


int main() {

	struct unittest test1 = {unittest1};
	struct unittest test2 = {unittest2};
	struct unittest test3 = {unittest3};
	struct unittest test4 = {unittest4};
	struct unittest card_test1 = {card_unittest1};
	struct unittest card_test2 = {card_unittest2};
	struct unittest card_test3 = {card_unittest3};
	struct unittest card_test4 = {card_unittest4};

	runner(&test1);
	runner(&test2);
	runner(&test3);
	runner(&test4);

	runner(&card_test1);
	runner(&card_test2);
	runner(&card_test3);
	runner(&card_test4);
}
