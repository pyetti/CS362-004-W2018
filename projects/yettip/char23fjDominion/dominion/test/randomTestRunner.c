/************************************************************************
Author: Peter Yetti 
Date:  2/13/18
Description: Implementation for randomTestRunner.c
*************************************************************************/

#include "unittest.h"

int main(int argc, char **argv) {
	struct unittest adventurer = {randomtestcard1};
	struct unittest smithy = {randomtestcard2};
//	struct unittest cutPurse = {randomtestcard3};

	adventurer.randomTestCount = 1000;
	smithy.randomTestCount = 1000;
//	cutPurse.randomTestCount = 1000;

	runner(&adventurer);
	runner(&smithy);
//	runner(&cutPurse);
	return 0;
}
